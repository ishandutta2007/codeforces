def solve():
    a, b = map(int, input().split())
    print((b - a % b) % b)


for i in range(int(input())):
    solve()