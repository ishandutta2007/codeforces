from sys import stdin


def solve():
    n, x = map(int, stdin.readline().split())
    cnt = 0
    for i in range(n - 1):
        u, v = map(int, stdin.readline().split())
        if u == x or v == x:
            cnt += 1
    if cnt <= 1 or n % 2 == 0:
        print("Ayush")
    else:
        print("Ashish")


tt = int(stdin.readline())
for _ in range(tt):
    solve()