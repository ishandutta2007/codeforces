import sys
range = xrange
input = raw_input


class segtree:
    def __init__(s, data):
        s.n = len(data)
        s.m = 1
        while s.m < s.n: s.m *= 2

        s.data = [0]*(s.m + s.m)
        s.data[s.m:s.m + s.n] = data
        for i in reversed(range(1, s.m)):
            s.data[i] = min(s.data[2 * i], s.data[2 * i + 1])
    def set(s, i, val):
        i += s.m
        while i:
            s.data[i] = val
            val = min(val, s.data[i ^ 1])
            i >>= 1

    def mini(s, l, r):
        l += s.m
        r += s.m
        
        val = s.data[l]
        while l < r:
            if l & 1:
                val = min(val, s.data[l])
                l += 1
            if r & 1:
                val = min(val, s.data[r - 1])
            l >>= 1
            r >>= 1
        return val

inp = [int(x) for x  in sys.stdin.read().split()]
ii = 0

t = inp[ii]
ii += 1

out = []
for _ in range(t):
    n = inp[ii]
    ii += 1
    A = inp[ii:ii + n]
    ii += n
    B = inp[ii:ii + n]
    ii += n

    Aseg = segtree(A)

    Aind = [[] for _ in range(n + 1)]
    for i in reversed(range(n)):
        Aind[A[i]].append(i)

    for b in B:
        if not Aind[b]:
            out.append('NO')
            break
        i = Aind[b].pop()
        if Aseg.mini(0, i) < b:
            out.append('NO')
            break
        Aseg.set(i, n + 1)
    else:
        out.append('YES')
print '\n'.join(out)