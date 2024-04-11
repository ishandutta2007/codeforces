n, t = map(int, input().split())

x = 10 ** (n - 1)
while x % t != 0 and x + 1 < 10 ** n:
    x += 1

if x % t == 0:
    print(x)
else:
    print(-1)