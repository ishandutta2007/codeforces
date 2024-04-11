def solve():
    n = int(input())
    a = sorted(map(int, input().split()))
    ans = (1, 0)
    cur = [a[0]]
    for i in range(1, n):
        if a[i] - a[i - 1] > 1:
            ans = max(ans, (len(cur), i - 1))
            cur.clear()
        elif a[i - 1] < a[i] and (i == n - 1 or a[i] < a[i + 1]):
            cur.append(a[i])
            ans = max(ans, (len(cur), i))
            cur.clear()
        cur.append(a[i])
    ans = max(ans, (len(cur), n - 1))
    print(ans[0])
    ans1 = []
    ans2 = []
    for i in a[ans[1]-ans[0]+1:ans[1]+1]:
        if not ans1 or ans1[-1] != i:
            ans1.append(i)
        else:
            ans2.append(i)
    print(*(ans1 + ans2[::-1]))


for _ in range(1):
    solve()