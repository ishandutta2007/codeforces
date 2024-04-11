import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
out = []
for _ in range(t):
    n = inp[ii]; ii += 1
    A = [a - 1 for a in inp[ii: ii + n]]; ii += n
    cur = [0]*200
    B = [list(cur)]
    C = [[] for _ in range(200)]
    for i in range(n):
        a = A[i]
        cur[a] += 1
        B.append(list(cur))
        C[a].append(i)

    ans = max(len(occ) for occ in C)
    for a in range(200):
        occ = C[a]
        for j in range(len(occ)//2):
            D1 = B[occ[j] + 1]
            D2 = B[occ[~j]]
            for k in range(200):
                ans = max(ans, 2 * (j + 1) + D2[k] - D1[k])
    out.append(ans)
print '\n'.join(str(x) for x in out)