import sys
range = xrange
input = raw_input

n, k = [int(x) for x in input().split()]
A = [int(x) - 1 for x in input().split()] if k else []

n = 2**n

marked = [0]*n
for a in A:
    marked[a] = 1

m = 1
while m < n: m *= 2

inf = 10**9

data = [[-inf]*(2*m) for _ in range(4)]
for i in range(0,n,2):
    data[0][(m + i) >> 1] = 0
    if marked[i]:
        data[1][(m + i) >> 1] = 1
        data[2][(m + i) >> 1] = 1
        if marked[i + 1]:
            data[3][(m + i) >> 1] = 1
    elif marked[i + 1]:
        data[1][(m + i) >> 1] = 1
        data[2][(m + i) >> 1] = 1

for i in reversed(range(m >> 1)):
    lchild = 2*i
    rchild = 2*i + 1

    for goal in range(4):
        for a in range(4):
            for b in range(4):
                if a | b == goal:
                    data[goal][i] = max(data[goal][i], data[a][lchild] + data[b][rchild] + (a & 1 or b & 1) + (a & 2 > 0 or b & 2 > 0) + (goal & 2 > 0))
print max(data[k][1] + (k > 0) for k in range(4))