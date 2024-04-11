from sys import stdin, stdout, setrecursionlimit
input = stdin.readline
print = stdout.write

for _ in range(int(input())):
    n, m = map(int, input().split())
    a, b = map(int, input().split())
    x = min(abs(m - n) * a + min(m, n) * b, (m + n) * a)
    print(str(x) + '\n')