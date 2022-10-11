import sys
range = xrange
input = raw_input

def query(x1,y1,x2,y2):
    print '?',x1,y1,x2,y2
    sys.stdout.flush()
    return int(input())

n = int(input())

x1 = 1
x2 = n

y1 = 1
y2 = n

a = 1
b = n
while a < b:
    c = a + b >> 1
    ans = query(x1,y1,c,y2)
    if ans:
        b = c
    else:
        a = c + 1
x2 = a

a = 1
b = n
while a < b:
    c = a + b >> 1
    ans = query(x1,y1,x2,c)
    if ans:
        b = c
    else:
        a = c + 1
y2 = a

a = 1
b = x2
while a < b:
    c = a + b + 1 >> 1
    ans = query(c,y1,x2,y2)
    if ans:
        a = c
    else:
        b = c - 1
x1 = a

a = 1
b = y2
while a < b:
    c = a + b + 1 >> 1
    ans = query(x1,c,x2,y2)
    if ans:
        a = c
    else:
        b = c - 1
y1 = a

X1 = x1
Y1 = y1
X2 = x2
Y2 = y2

def query(x1,y1,x2,y2):
    print '?',x1,y1,x2,y2
    sys.stdout.flush()
    return int(input()) - (x1 <= X1 and X2 <= x2 and y1 <= Y1 and Y2 <= y2)

x1 = 1
x2 = n

y1 = 1
y2 = n

a = 1
b = n
while a < b:
    c = a + b >> 1
    ans = query(x1,y1,c,y2)
    if ans:
        b = c
    else:
        a = c + 1
x2 = a

a = 1
b = n
while a < b:
    c = a + b >> 1
    ans = query(x1,y1,x2,c)
    if ans:
        b = c
    else:
        a = c + 1
y2 = a

a = 1
b = x2
while a < b:
    c = a + b + 1 >> 1
    ans = query(c,y1,x2,y2)
    if ans:
        a = c
    else:
        b = c - 1
x1 = a

a = 1
b = y2
while a < b:
    c = a + b + 1 >> 1
    ans = query(x1,c,x2,y2)
    if ans:
        a = c
    else:
        b = c - 1
y1 = a

print '!',x1,y1,x2,y2,X1,Y1,X2,Y2