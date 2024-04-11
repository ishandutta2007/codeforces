def solve():
    k = int(input())
    group = input() + "A"
    prev = -1
    ans = 0
    for i in range(k + 1):
        if group[i] == "A":
            if prev != -1:
                ans = max(i - prev - 1, ans)
            prev = i
    print(ans)


t = int(input())
for _ in range(t):
    solve()