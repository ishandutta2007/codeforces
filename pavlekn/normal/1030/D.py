n, m, k = map(int, input().split())
if ((2 * n * m) % k != 0):
    print("NO")
else:
    if (k == 2):
        print("YES")
        print(0, 0)
        print(n, 0)
        print(0, m)
    else:
        s = (n * m) / k
        s = int(s * 2)
        print("YES")
        print(0, 0)
        print(n, 1)
        print(((n - 1) - (s - 1) % n), (s - 1) // n + 1)