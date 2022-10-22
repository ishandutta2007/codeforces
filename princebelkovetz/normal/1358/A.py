from sys import stdin, stdout, setrecursionlimit
input = stdin.readline

for _ in range (int(input())):
    n, m = map(int, input().split())
    if (m % 2 == 0):
        ans = n * (m // 2)
    else:
        ans = n * ((m - 1) // 2)
        ans += n // 2 + n % 2
    print(ans)