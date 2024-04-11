import math

# init
maxn = 55
g = [1]
for i in range(maxn):
    g.append(math.factorial(i))
f = [0] * maxn
f[0] = 1
for i in range(1, maxn):
    for j in range(i):
        f[i] += f[j] * g[i - j - 1]

def kth(n, k):
    if n == 1:
        return [1]
    ret = [-1] * n
    ret[0] = n - 1
    p1 = [i for i in range(n)]
    p2 = [i for i in range(n)]
    vis = [False] * n
    p1[0] = n - 1
    p2[n - 1] = 0
    vis[n - 1] = True
    for i in range(1, n - 1):
        j = 0
        now = math.factorial(n - i - 2)
        while True:
            while vis[j] or (i < n - 1 and j == p2[i]):
                j += 1
            if k > now:
                k -= now
                j += 1
            else:
                p1[p2[i]] = p1[j]
                p2[p1[j]] = p2[i]
                ret[i] = j
                vis[j] = True
                break
    ret[-1] = p2[-1]
    return [x + 1 for x in ret]

def solve(n, k):
    if n == 0:
        return []
    i = 1
    while g[i - 1] * f[n - i] < k:
        k -= g[i - 1] * f[n - i]
        i += 1
    rem = solve(n - i, (k - 1) % f[n - i] + 1)
    rem = [x + i for x in rem]
    k = (k - 1) // f[n - i] + 1
    return kth(i, k) + rem

def SOLVE():
    n, k = map(int, input().split())
    if k > f[n]:
        print(-1)
        return
    ans = solve(n, k)
    for x in ans:
        print(x, end = " ")
    print()

T = int(input())
while T > 0:
    T -= 1
    SOLVE()