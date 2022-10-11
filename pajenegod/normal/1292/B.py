import sys
range = xrange
input = raw_input

x0,y0,ax,ay,bx,by = [int(x) for x in input().split()]

xs,ys,t = [int(x) for x in input().split()]

X = [x0]
Y = [y0]
while X[-1] < 10**18 and Y[-1] < 10**18:
    X.append(X[-1] * ax + bx)
    Y.append(Y[-1] * ay + by)

m = len(X)

besta = 0
for i in range(m):
    for j in range(i + 1):
        for k in range(i, m):
            x = xs
            y = ys
            count = 0
            time = 0

            time += abs(X[i] - x) + abs(Y[i] - y)
            x = X[i]
            y = Y[i]
            count += 1

            for ind in reversed(range(j, i)):
                time += abs(X[ind] - x) + abs(Y[ind] - y)
                count += 1
                x = X[ind]
                y = Y[ind]
            
            for ind in range(i+1, k):
                time += abs(X[ind] - x) + abs(Y[ind] - y)
                count += 1
                x = X[ind]
                y = Y[ind]
            if time <= t:
                besta = max(besta, count)
print besta