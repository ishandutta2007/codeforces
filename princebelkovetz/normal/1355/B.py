from sys import stdin, stdout, setrecursionlimit
input = stdin.readline
print = stdout.write
# map(int, input().split())

for _ in range(int(input())):
    n = int(input())
    a = sorted([int(i) for i in input().split()])
    cou = 0
    ans = 0
    for i in range(n):
        cou += 1
        if a[i] <= cou:
            ans += 1
            cou = 0
    print(str(ans) + '\n')