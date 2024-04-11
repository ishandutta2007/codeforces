import sys
import itertools
range = xrange
input = raw_input

inp = [float(x) for x in sys.stdin.read().split()]; ii = 0

t = int(inp[ii]); ii += 1
for _ in range(t):
    X = inp[ii + 0: ii + 8: 2]
    Y = inp[ii + 1: ii + 8: 2]
    ii += 8

    XX = sorted(X)
    YY = sorted(Y)
    orders = list(itertools.permutations(range(4)))

    besta = 1e18

    for x1,x2 in itertools.combinations(XX, 2):
        for a,b,c,d in orders:
            xa = X[a] - x1
            xb = X[b] - x1
            xc = X[c] - x2
            xd = X[d] - x2
            
            cand1 = abs(xa) + abs(xb) + abs(xc) + abs(xd)

            for y1 in YY:
                y2 = y1 + x2 - x1
                
                ya = Y[a] - y1
                yb = Y[b] - y2
                yc = Y[c] - y1
                yd = Y[d] - y2

                cand2 = abs(ya) + abs(yb) + abs(yc) + abs(yd)
                besta = min(besta, cand1 + cand2)
            
            for y2 in YY:
                y1 = y2 - (x2 - x1)
                
                ya = Y[a] - y1
                yb = Y[b] - y2
                yc = Y[c] - y1
                yd = Y[d] - y2

                cand2 = abs(ya) + abs(yb) + abs(yc) + abs(yd)
                besta = min(besta, cand1 + cand2)
    
    for y1,y2 in itertools.combinations(YY, 2):
        for a,b,c,d in orders:
            ya = Y[a] - y1
            yb = Y[b] - y1
            yc = Y[c] - y2
            yd = Y[d] - y2
            
            cand1 = abs(ya) + abs(yb) + abs(yc) + abs(yd)

            for x1 in XX:
                x2 = x1 + y2 - y1
                
                xa = X[a] - x1
                xb = X[b] - x2
                xc = X[c] - x1
                xd = X[d] - x2

                cand2 = abs(xa) + abs(xb) + abs(xc) + abs(xd)
                besta = min(besta, cand1 + cand2)
            
            for x2 in XX:
                x1 = x2 - (y2 - y1)
                
                xa = X[a] - x1
                xb = X[b] - x2
                xc = X[c] - x1
                xd = X[d] - x2

                cand2 = abs(xa) + abs(xb) + abs(xc) + abs(xd)
                besta = min(besta, cand1 + cand2)
    print int(besta)