import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    S = input()
    Rcount = [0]
    Ucount = [0]
    for c in S:
        r = 0
        u = 0
        if c == 'R':
            r = 1
        elif c == 'L':
            r = -1
        elif c == 'U':
            u = 1
        else:
            u = -1
        Rcount.append(Rcount[-1] + r)
        Ucount.append(Ucount[-1] + u)
    
    best = n + 100
    bestind = -1
    found = {}
    for i in range(n + 1):
        r = Rcount[i]
        u = Ucount[i]
        if (r,u) not in found:
            found[r,u] = i
        else:
            val = i - found[r,u]
            if val < best:
                best = val
                bestind = i
            found[r,u] = i
    if bestind != -1:
        i = bestind
        j = -best + i
        print j + 1, i
    else:
        print -1