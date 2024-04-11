from sys import stdin, stdout, setrecursionlimit
input = stdin.readline

for _ in range (int(input())):
    n, m, k = map(int, input().split())
    x = n // k
    if x > m:
        print(m)
    else:
        m -= x
        k -= 1
        x -= (k - 1 + m) // k
        print(x)