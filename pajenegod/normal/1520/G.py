import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1
w = inp[ii]; ii += 1

B = inp[ii: ii + n * m]; ii += n * m

A = [-1] * ((n + 1) * (m + 1))
for i in range(n):
    for j in range(m):
        A[i * (m + 1) + j] = B[i * m + j]

n += 1
m += 1


def bfser(root):
    D = [-1 if A[ind] >= 0 else -2 for ind in range(n * m)]
    D[root] = 0
    bfs = [root]
    for ind in bfs:
        d = D[ind] + 1
        for ind2 in ind+1, ind-1, ind+m, ind-m:
            if D[ind2] == -1:
                D[ind2] = d
                bfs.append(ind2)
    return D


start = 0
D1 = bfser(0)
goal = (n - 1) * m - 2
D2 = bfser(goal)

best = D1[goal] * w
if best < 0:
    best = 10**18

best_enter = 10**18
best_exit = 10**18

for ind in range(n * m):
    if A[ind] > 0:
        if D1[ind] >= 0:
            best_enter = min(best_enter, D1[ind] * w + A[ind])
        if D2[ind] >= 0:
            best_exit = min(best_exit, D2[ind] * w + A[ind])

ans = min(best_enter + best_exit, best)
print ans if ans < 10**18 else -1