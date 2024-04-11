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
            s.data[i] += x
            i >>= 1
    def summa(s, l, r):
        l += s.m
        r += s.m
        x = 0
        while l < r:
            if l&1:
                x += s.data[l]
                l += 1
            if r&1:
                r -= 1
                x += s.data[r]
            l >>= 1
            r >>= 1
        return x
 
orda = ord('a')
S = [ord(c) - orda for c in sys.stdin.readline().rstrip()]
n = len(S)
segs = [segtree(n) for _ in range(26)]
for i in range(n):
    segs[S[i]].add(i, 1)
 
inp = sys.stdin.read().split(); ii = 0
 
out = []
q = int(inp[ii]); ii += 1
for _ in range(q):
    case = inp[ii]; ii += 1
    if case == '1':
        i = int(inp[ii]) - 1; ii += 1
        c = ord(inp[ii]) - orda; ii += 1
 
        segs[S[i]].add(i, -1)
        S[i] = c
        segs[S[i]].add(i, 1)
    else:
        l = int(inp[ii]) - 1; ii += 1
        r = int(inp[ii]); ii += 1
        out.append(sum(seg.summa(l,r) > 0 for seg in segs))
print '\n'.join(str(x) for x in out)