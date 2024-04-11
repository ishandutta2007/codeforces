def solve():
    n = int(input())
    arr = sorted(map(int, input().split()))
    ans = 0
    cur = set()
    for i in arr:
        while i not in cur and i % 2 == 0:
            cur.add(i)
            ans += 1
            i //= 2
    print(ans)



t = int(input())
for _ in range(t):
    solve()