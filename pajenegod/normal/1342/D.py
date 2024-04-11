import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]
M = [int(x) - 1 for x in input().split()]
C = [int(x) for x in input().split()]

M.sort()

ans = []
for i in reversed(range(n)):
    if i == n - 1 or C[M[i]] != C[M[i + 1]]:
        ii = 0

    while True:
        if ii == len(ans):
            ans.append([])
        elif len(ans[ii]) == C[M[i]]:
            ii += 1
        else:
            ans[ii].append(M[i])
            break
out = []
out.append(len(ans))
for a in ans:
    out.append(len(a))
    for x in a:
        out.append(x + 1)

print '\n'.join(str(x) for x in out)