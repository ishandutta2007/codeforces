T = int(input())
for _ in range(T):
    n = int(input())
    A = list(map(int, input().split()))
    A.reverse()
    ans = []
    temp = []
    ma = -1
    for i2 in range(0, n):
        i = n-i2-1
        if A[i] > ma:
            ma = A[i]
            temp.reverse()
            for t in temp:
                ans.append(t)
            temp = []
        temp.append(A[i])
    temp.reverse()
    for t in temp:
        ans.append(t)
    ans.reverse()
    print(*ans)