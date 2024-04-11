from sys import stdin, stdout, setrecursionlimit
input = stdin.readline
print = stdout.write


for _ in range(int(input())):
    ans = 'yes'
    n, a, b, c, d = map(int, input().split())
    if (a - b) * n > c + d or (a + b) * n < c - d:
        print('no\n')
    else:
        print('yes\n')