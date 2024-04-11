import sys
range = xrange
input = raw_input

n = int(input())
Q = [int(x) for x in input().split()]

P = [0]
for q in Q:
    P.append(P[-1]+q)

minP = min(P)
P = [p-minP+1 for p in P]

if sorted(P) == sorted(range(1,n+1)):
    print ' '.join(str(x) for x in P)
else:
    print -1