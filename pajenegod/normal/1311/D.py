import sys
range = xrange
input = raw_input
 
upper = 10**4
 
t = int(input())
for _ in range(t):
    a,b,c = [int(x) for x in input().split()]
 
    best = a - 1 + b - 1 + c - 1
    besta,bestb,bestc = 1,1,1
    for i in range(1, 2 * upper + 1):
        for j in range(i, 2 * upper + 1, i):
            cand1 = (c // j) * j
            cost1 = abs(a - i) + abs(b - j) + abs(c - cand1) 
            cand2 = cand1 + j
            cost2 = abs(a - i) + abs(b - j) + abs(c - cand2) 
            if 1 <= cand1 and cost1 < best:
                best = cost1
                besta,bestb,bestc = i,j,cand1
            if 1 <= cand2 and cost2 < best:
                best = cost2
                besta,bestb,bestc = i,j,cand2
    print best
    print besta, bestb, bestc