from sys import stdin, stdout, setrecursionlimit
for _ in range(int(input())):
    n = int(input())
    a = [[int(i)] for i in input().split()]
    for i in range(n):
        a[i].append(i)
    a = sorted(a)
    ans = 1
    cur = 1
    #print(a)
    for i in range(1, n):
        if a[i][1] > a[i - 1][1]:
            cur += 1
        else:
            ans = max(ans, cur)
            cur = 1
        if i == n - 1:
            ans = max(ans, cur)
            cur = 1
    print(n - ans)