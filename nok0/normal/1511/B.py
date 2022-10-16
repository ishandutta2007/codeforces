t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    x = pow(10, c - 1) * pow(10, a - c)
    y = pow(10, c - 1) * pow(11, b - c)
    print(x, y)