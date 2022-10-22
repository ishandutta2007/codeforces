from sys import stdin, stdout, setrecursionlimit
for _ in range(1):
    n = int(input())
    a = [int(i) for i in input().split()]
    f = True
    ans = [-1] * n
    ok = [False] * (n + 1)
    for i in range(n):
        if a[i] > i + 1 or a[i] > a[min(i + 1, n - 1)]:
            f = False
            break
        ok[a[i]] = True
    if not f:
        print(-1)
        continue
    nums = []
    curi = 0
    for i in range(n + 1):
        if not ok[i]:
            nums.append(i)
    for i in range(n - 1):
        if a[i] != a[i + 1]:
            ans[i + 1] = a[i]
    for i in range(n):
        if ans[i] == -1:
            ans[i] = nums[curi]
            curi += 1

    print(*ans)