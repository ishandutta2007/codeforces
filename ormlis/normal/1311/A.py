from sys import stdin


def solve():
    a, b = map(int, input().split())
    if a == b:
        print(0)
    elif (b - a) % 2 and a < b:
        print(1)
    elif (a - b) % 2 == 0 and a > b:
        print(1)
    else:
        print(2)


for i in range(int(input())):
    solve()