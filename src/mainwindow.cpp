// Copyright (c) 2013 Artem Andreenko <mio@volmy.com>

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include <QtQml/QQmlEngine>
#include "mainwindow.hpp"
#include <QtGui/QBitmap>
#include <QtGui/QPainter>

namespace VolmyDesktop
{

MainWindow::MainWindow(QWindow *parent)
    : QQuickView(parent)
{
    connect(engine(), SIGNAL(quit()), SLOT(close()));
//    connect(this, SIGNAL(widthChanged(int)), this, SLOT(redrawBorders()));
//    connect(this, SIGNAL(heightChanged(int)), this, SLOT(redrawBorders()));
    setResizeMode(QQuickView::SizeRootObjectToView);
    setFlags(Qt::FramelessWindowHint);
}

void MainWindow::redrawBorders()
{
    QBitmap objBitmap(size());
    QPainter painter;
    QRect rect(position(), QPoint(position().x() + width(), position().y() + height()));
    painter.fillRect(rect,Qt::white);
    painter.setBrush(QColor(0,0,0));
    painter.drawRoundedRect(rect,10,10);
    setMask(objBitmap);
}

void MainWindow::setMainQmlFile(const QString &file)
{
    setSource(QUrl(file));
}

void MainWindow::showExpanded()
{
#if defined(Q_WS_SIMULATOR) || defined(Q_OS_QNX)
    showFullScreen();
#else
    show();
#endif
}

MainWindow::~MainWindow()
{
}

}
