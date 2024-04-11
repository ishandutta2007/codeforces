import sys
range = xrange
input = raw_input

n = int(input())

X = []
Y = []

for t in range(1,n+1):
    print '?', t, 1, t, n
    X.append(int(input()))

    print '?', 1, t, n, t
    Y.append(int(input()))

diffx = sum(1 for x in X if x&1)>1
diffy = sum(1 for y in Y if y&1)>1

assert diffx or diffy

# head and tail have different x
if diffx:
    i = 0
    while X[i]&1==0:i+=1
    x1 = i+1
    i += 1
    while X[i]&1==0:i+=1
    x2 = i+1

if diffy:
    i = 0
    while Y[i]&1==0:i+=1
    y1 = i+1
    i += 1
    while Y[i]&1==0:i+=1
    y2 = i+1

if diffx and diffy:
    print '?',x1,y1,x1,y1
    if int(input())&1==0:
        x1,x2 = x2,x1

if not diffx:
    l = 1
    r = n
    while l<r:
        m = (l+r)//2
        print '?', 1, y1, m, y1
        tmp = int(input())
        if tmp&1:
            r = m
        else:
            l = m+1
    x1 = x2 = l

if not diffy:
    l = 1
    r = n
    while l<r:
        m = (l+r)//2
        print '?', x1, 1, x1, m
        tmp = int(input())
        if tmp&1:
            r = m
        else:
            l = m+1
    y1 = y2 = l

print '!', x1, y1, x2, y2