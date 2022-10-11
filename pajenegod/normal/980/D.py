from collections import defaultdict as di
import sys
range = xrange
input = raw_input

n = int(input())

A = []
for a in [int(x) for x in input().split()]:
    sign = 1 - 2*(a < 0)
    a = abs(a)

    i = 3
    j = 4
    while j <= a:
        while a % j == 0:
            a //= j
        i += 2
        j += i
    A.append(sign * a)

mapper = di(lambda:len(mapper))
A = [mapper[a] if a != 0 else -1 for a in A]
m = len(mapper)
pos = [[] for _ in range(m)]
for i in reversed(range(n)):
    if A[i] != -1:
        pos[A[i]].append(i)

val = [+(A[i] != -1 and pos[A[i]][-1] == i) for i in range(n)]
for a in range(m):
    pos[a].pop()

next_nonzero = []
last = n
for i in reversed(range(n)):
    if A[i] != -1:
        last = i
    next_nonzero.append(last)
next_nonzero.reverse()


ans = [0]*(n+1)
for i in range(n):
    if A[i] == -1:
        val[i] += 1
        nesta = next_nonzero[i]
        if nesta < n:
            val[nesta] = 0
    
    s = 0
    for j in range(i, n):
        s += val[j]
        ans[s] += 1
    
    if A[i] != -1:
        if pos[A[i]]:
            val[pos[A[i]].pop()] += 1
    else:
        if nesta < n:
            val[nesta] = 1

print ' '.join(str(ans[i]) for i in range(1, n + 1))