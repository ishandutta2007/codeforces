n, m, k = map(int, input().split())
if (k == -1 and (n % 2 + m % 2) % 2 == 1):
    print(0)
else:
    print(pow(2, (n - 1) * (m - 1), 1000000007))