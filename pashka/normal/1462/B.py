def solve():
    n = int(input())
    s = input()
    for i in range(5):
        ss = s[:i] + s[n - 4 + i:]
        if ss == "2020":
            print("YES")
            return
    print("NO")


n = int(input())
for i in range(n):
    solve()