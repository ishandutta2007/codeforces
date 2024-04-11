def solve():
    x = input()
    y = input().rjust(len(x), '0')
    j = y.rfind('1')
    i = x.rfind('1', 0, j + 1)
    print(j - i)


for _ in range(int(input())):
    solve()