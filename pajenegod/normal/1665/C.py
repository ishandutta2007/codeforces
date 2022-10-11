import sys
from collections import defaultdict
input = sys.stdin.readline

t = int(input())
for cas in range(t):
    n = int(input())

    graph = [[] for _ in range(n)]
    
    child_count = [0] * n

    P = [int(x) - 1 for x in input().split()]
    for u in range(1,n):
        v = P[u - 1]
        child_count[v] += 1
    
    child_count.append(1) # root
    child_count.sort(reverse = True)
    while child_count and child_count[-1] == 0:
        child_count.pop()
   
    # Check if doable in T time
    def check(T):
        extra = 0
        for t in range(len(child_count)):
            extra += max(0, (t + child_count[t]) - T)
        return len(child_count) + extra <= T

    l = 0
    r = n + 3
    while l < r:
        m = (l + r) // 2
        if check(m):
            r = m
        else:
            l = m + 1

    print(l)