def solve():
    n = int(input())
    s = input()
    t = ''.join(filter(lambda x: int(x) % 2, s))
    if len(t) >= 2:
        print(t[:2])
    else:
        print(-1)


t = int(input())
for _ in range(t):
    solve()