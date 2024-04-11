import sys
range = xrange
input = raw_input

class segtree:
    def __init__(s, n):
        s.m = 1
        while s.m < n: s.m *= 2
        s.data = [0]*(2 * s.m)
    
    def add(s, i, x):
        i += s.m
        while i:
            s.data[i] += 1
            i >>= 1

    def first(s, l, r):
        l += s.m
        r += s.m

        best = -1
        while l < r:
            if l & 1:
                if s.data[l]:
                    best = l
                    break
                l += 1
            if r & 1:
                r -= 1
                if s.data[r]:
                    best = r
            l >>= 1
            r >>= 1
        if best == -1:
            return -1
        
        while best < s.m:
            best <<= 1
            if not s.data[best]:
                best += 1
        return best - s.m

n = int(input())

A = [int(x) for x in input().split()]

B = A * 2
reach = [-1]*(2 * n)

stack = []
for i in reversed(range(2*n)):
    while stack and B[stack[-1]] >= B[i]:
        stack.pop()
    
    a = -1
    b = len(stack) - 1
    while a < b:
        c = a + b + 1 >> 1
        if 2 * B[stack[c]] < B[i]:
            a = c
        else:
            b = c - 1

    reach[i] = stack[a] if a != -1 else -1
    stack.append(i)

seg = segtree(2 * n)

ans = [-1]*(2*n)
for i in sorted(range(n), key = A.__getitem__, reverse=True):
    l = i
    r = reach[i]
    if r == -1:
        r = 2 * n

    j = seg.first(l,r)
    if j >= 0:
        ans[i] = ans[j]
        ans[i + n] = ans[j] + n if ans[j] != -1 else -1
    else:
        ans[i] = reach[i]
        ans[i + n] = ans[i] + n if ans[i] != -1 else -1
    
    seg.add(i, 1)
    seg.add(i + n, 1)

out = []
for i in range(n):
    out.append(-1 if ans[i] == -1 else ans[i] - i)
print ' '.join(str(x) for x in out)