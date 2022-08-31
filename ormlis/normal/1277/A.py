def solve():
    n = int(input())
    s = str(n)
    a = s[0]
    for i in s:
        if i > a:
            break
        if i < a:
            a = int(a) - 1
            break
    a = int(a)
    print(a + 9 * (len(s) - 1))


t = int(input())
for _ in range(t):
    solve()