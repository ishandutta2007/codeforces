import sys
from collections import defaultdict as di

n = int(input())
A = [int(x) for x in input().split()]

C = di(int)
CC = di(int)

for a in A:
    C[a] += 1

for c in C:
    CC[C[c]] += 1

for a in reversed(A):
    if len(CC) == 2:
        aa,bb = sorted(list(CC.items()))
        k1,v1 = aa
        k2,v2 = bb
        if (k2-k1 == 1 and v2 == 1) or (k1 == 1 and v1 == 1):
            print(n)
            sys.exit()
    elif len(CC) == 1:
        aa, = list(CC.items())
        k1,v1 = aa
        if k1 == 1 or v1 == 1:
            print(n)
            sys.exit()

    CC[C[a]] -= 1
    if CC[C[a]] == 0:
        del CC[C[a]]
    C[a] -= 1
    if C[a] == 0:
        del C[a]
    if C[a]:
        CC[C[a]] += 1

    n -= 1