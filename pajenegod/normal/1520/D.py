import sys
from collections import defaultdict as di
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    A = [A[i] - i for i in range(n)]

    count = di(int)
    for a in A:
        count[a] += 1

    total = 0
    for a in count:
        total += count[a] * (count[a] - 1) // 2
    print total