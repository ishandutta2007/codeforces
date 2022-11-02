n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    if (a + b) % 3 == 0 and b >= a - b and a >= b - a:
        print("YES")
    else:
        print("NO")