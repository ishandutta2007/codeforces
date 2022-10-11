import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,k = [int(x) for x in input().split()]
    
    minpos = n & 1
    maxpos = n

    cost = 0
    if minpos != k & 1:
        cost += 1
        n += 1
        minpos ^= 1
        maxpos = n

    if minpos <= k <= maxpos:
        print cost
    else:
        if k == 0:
            print cost + 1
        else:
            print k - n + cost