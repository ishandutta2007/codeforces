t = int(input())
for query in range(t):
    n = int(input())
    A = list(map(int, input().split()))
    ansi = -1
    for i in range(n - 1):
        if abs(A[i] - A[i + 1]) > 1:
            ansi = i
    if ansi == -1:
        print('NO')
    else:
        print('YES')
        print(ansi + 1, ansi + 2)