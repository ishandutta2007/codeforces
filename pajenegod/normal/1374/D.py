import sys
from collections import defaultdict
range = xrange
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n,k = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]

    counter = defaultdict(int)
    for a in A:
        if a % k != 0:
            counter[(k - a) % k] += 1

    maxcount = 1
    val = -1
    for a in counter:
        if counter[a] > maxcount or (counter[a] == maxcount and a > val):
            maxcount = counter[a]
            val = a
    print (maxcount - 1) * k + val + 1