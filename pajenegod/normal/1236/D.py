import sys
range = xrange
input = raw_input


inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

Xp = [[] for _ in range(n)]
#Xm = [[] for in range(n)]

Yp = [[] for _ in range(m)]
#Ym = [[] for in range(m)]


k = inp[ii]; ii += 1
for _ in range(k):
    y = inp[ii] - 1; ii += 1
    x = inp[ii] - 1; ii += 1
    Xp[y].append(x)
    Yp[x].append(y)

Xm = []
for X in Xp:
    X.sort()
    Xm.append(X[::-1])

Ym = []
for Y in Yp:
    Y.sort()
    Ym.append(Y[::-1])

d = 0
x = 0
y = 0


xmin = 0
xmax = m - 1

ymin = 1
ymax = n - 1


if (Xp[0] and Xp[0][0] == 1) or m == 1:
    d = 1
    xmax = 0

dist = 0

while True:
    if d == 0:
        X = Xp[y]
        xwall = m - 1
        while X and X[-1] >= x:
            xwall = X.pop() - 1
        xmax = min(xmax, xwall)
        
        if x == xmax:
            break
        dist += xmax - x
        x = xmax
        
        xmax -= 1
    elif d == 1:
        Y = Yp[x]
        ywall = n - 1
        while Y and Y[-1] >= y:
            ywall = Y.pop() - 1
        ymax = min(ymax, ywall)
        
        if y == ymax: break
        dist += ymax - y
        y = ymax

        ymax -= 1
    elif d == 2:
        X = Xm[y]
        xwall = 0
        while X and X[-1] <= x:
            xwall = X.pop() + 1
        
        xmin = max(xmin, xwall)
        
        if x == xmin: break
        dist += x - xmin
        x = xmin
        
        xmin += 1
    else:
        Y = Ym[x]
        ywall = 0
        while Y and Y[-1] <= y:
            ywall = Y.pop() + 1
        ymin = max(ymin, ywall)
        
        if y == ymin: break
        
        dist += y - ymin
        y = ymin
        
        ymin += 1
    d = (d + 1)&0b11

if n*m - k - 1 == dist:
    print 'Yes'
else:
    print 'No'