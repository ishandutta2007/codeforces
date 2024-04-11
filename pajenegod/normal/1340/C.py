import sys
range = xrange
input = raw_input

_,n = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
A.sort()
g,r = [int(x) for x in input().split()]

D = []
for i in range(n - 1):
    D.append(A[i + 1] - A[i])

found = [0]*((g + 1)*n)

count = -1
finder = False
next_layer = [0]
while next_layer and not finder:
    count += 1
    bfs = next_layer
    next_layer = []
    for node in bfs:
        t,i = divmod(node, n)
        if i > 0:
            tp = t + D[i - 1]
            ind = i - 1 + n * tp
            if tp <= g and not found[ind]:
                found[ind] = 1
                if tp == g:
                    next_layer.append(i - 1)
                else:
                    bfs.append(ind)
        if i + 1 < n:
            tp = t + D[i]
            ind = i + 1 + n * tp
            if tp <= g and not found[ind]:
                found[ind] = 1
                if i + 1 == n - 1:
                    finder = True
                elif tp == g:
                    next_layer.append(i + 1)
                else:
                    bfs.append(ind)

if finder:
    print count*(g+r) + min(i for i in range(1, g + 1) if found[n - 1 + i * n])
else:
    print -1