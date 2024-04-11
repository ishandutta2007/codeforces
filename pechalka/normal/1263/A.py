t = int(input())
for i in range(t):
    r, g, b = map(int, input().split())
    if 2 * max(r, g, b) >= (r + g + b):
        print(r + g + b - max(r, g, b))
    else:
        print((r + g + b) // 2)