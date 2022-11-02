T = int(input())
for i in range(T):
    n, m = map(int, input().split())
    A = [0] * n
    B = [0] * m
    for i in range(n):
        tmp = list(map(int, input().split()))
        for j in range(m):
            if tmp[j] == 1:
                B[j] = 1
                A[i] = 1
    cnt = min(n - sum(A), m - sum(B))
    if cnt % 2 == 1:
        print('Ashish')
    else:
        print('Vivek')