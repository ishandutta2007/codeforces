from sys import stdin


def solve():
    n, x = map(int, stdin.readline().split())
    a = list(map(int, stdin.readline().split()))
    nc = [i for i in a if i % 2 == 1]
    if not nc or (len(nc) % 2 == 0 and x == n) or (len(nc) == n and x % 2 == 0):
        print("No")
    else:
        print("Yes")


tt = int(stdin.readline())
for _ in range(tt):
    solve()