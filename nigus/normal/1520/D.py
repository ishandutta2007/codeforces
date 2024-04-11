t = int(input())
for _ in range(t):
    n = int(input())
    A = list(map(int ,input().split()))
    for i in range(n):
        A[i] -= i
    M = {}
    ans = 0
    for a in A:
        if a not in M:
            M[a] = 0
        ans += M[a]
        M[a] += 1
    print(ans)