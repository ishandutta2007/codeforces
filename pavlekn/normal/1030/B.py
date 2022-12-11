n, d = map(int, input().split())
m = int(input())
for i in range(m):
    x, y = map(int, input().split())
    if (abs(y - x) <= d and x + y >= d and x + y <= 2 * n - d):
        print("YES")
    else:
        print("NO")