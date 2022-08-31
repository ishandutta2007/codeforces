from sys import stdin
n, x, y = map(int, stdin.readline().split())
a = list(map(int, stdin.readline().split()))
ans = -1
for i in range(n):
    flag = 1
    for j in range(max(i - x, 0), min(i + y + 1, n)):
        if j == i:
            continue
        if a[j] <= a[i]:
            flag = 0
    if flag:
        print(i + 1)
        break