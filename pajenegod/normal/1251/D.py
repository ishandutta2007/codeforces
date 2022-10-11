import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0

ans = []
t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    s = int(inp[ii]); ii += 1

    L = [int(x) for x in inp[ii    :ii + 2 * n: 2]]
    R = [int(x) for x in inp[ii + 1:ii + 2 * n: 2]]
    ii += 2 * n

    order = sorted(range(n), key = L.__getitem__)
    L = [L[i] for i in order]
    R = [R[i] for i in order]

    s -= sum(L)
    s = int(s)

    a = sorted(L)[n//2]
    b = max(R)
    while a < b:
        c = a + b + 1 >> 1

        picks = [L[i] for i in range(n) if R[i]>= c]
        if len(picks) < n//2 + 1:
            b = c - 1
            continue
        
        extra = sum(max(0, c - p) for p in picks[-(n//2 + 1):])
        if extra <= s:
            a = c
        else:
            b = c - 1
    ans.append(a)

print '\n'.join(str(c) for c in ans)