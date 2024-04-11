import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n,q = [int(x) for x in input().split()]
    N = M = 1002
    A = [[0] * M for _ in range(N)]

    for _ in range(n):
        h,w = [int(x) for x in input().split()]
        A[h][w] += h*w

    for i in range(1, N):
        for j in range(1, M):
            A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1]

    for _ in range(q):
        h1,w1,h2,w2 = [int(x) for x in input().split()]

        h2 -= 1
        w2 -= 1
        print(A[h2][w2] - A[h2][w1] - A[h1][w2] + A[h1][w1])