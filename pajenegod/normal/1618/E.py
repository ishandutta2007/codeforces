import sys

MOD = 10**9 + 7

t = int(input())
for _ in range(t):
    n, = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]

    m = sum(i for i in range(1, n + 1))

    sumA = sum(A)
    if sumA % m != 0:
        print('NO')
        continue
    s = sumA // m

    B = [s + A[i - 1] - A[i] for i in range(n)]
    for b in B:
        if b % n != 0 or not 1 <= b // n <= 10**9:
            print('NO')
            break
    else:
        print('YES')
        print(' '.join(str(b // n) for b in B))