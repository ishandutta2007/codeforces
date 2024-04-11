import sys
range = xrange
input = raw_input

class segtree:
    def __init__(s, data):
        s.n = len(data)
        s.m = 1
        while s.m < s.n: s.m *= 2
        s.data = [0]*s.m
        s.data += data
        for i in reversed(range(2, s.n + s.m)):
            s.data[i >> 1] += s.data[i]

    def add(s, i, x):
        i += s.m
        while i:
            s.data[i] += x
            i >>= 1

    def summa(s, l, r):
        l += s.m
        r += s.m

        tot = 0
        while l<r:
            if l & 1:
                tot += s.data[l]
                l += 1
            if r & 1:
                tot += s.data[r - 1]

            l >>= 1
            r >>= 1
        return tot

def trans(x):
    if x == 'A':
        return 0
    elif x == 'C':
        return 1
    elif x == 'G':
        return 2
    return 3

inp = sys.stdin.read().split()
ii = 0

S = [trans(x) for x in inp[ii]]
ii += 1

segs =  [
            [
                [
                    segtree([+(s==c) for s in S[j::i]]) for c in range(4)
                ] 
                for j in range(i)
            ] 
            for i in range(11)
        ]

q = int(inp[ii])
ii += 1
out = []
for _ in range(q):
    c = inp[ii]
    ii += 1
    if c == '1':
        ind = int(inp[ii]) - 1
        ii += 1
        char = trans(inp[ii])
        ii += 1

        old_char = S[ind]
        for i in range(1,11):
            seg = segs[i][ind % i]
            seg[old_char].add(ind // i, -1)
            seg[char].add(ind // i, 1)

        S[ind] = char
    else:
        l = int(inp[ii]) - 1
        ii += 1
        r = int(inp[ii])
        ii += 1

        e = inp[ii]
        ii += 1

        tot = 0

        i = len(e)
        for k in range(i):
            L = l + k
            start = L//i
            length = (r - L + i - 1)//i
            tot += segs[i][L % i][trans(e[k])].summa(start, start + length)
        out.append(tot)

print '\n'.join(str(x) for x in out)