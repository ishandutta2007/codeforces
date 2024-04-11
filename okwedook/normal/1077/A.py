t = int(input())
for i in range(t):
    a, b, k = map(int, input().split())
    print((k - k // 2) * a - k // 2 * b)