m = 1000000007
x, k = map(int, input().split())
up = (x * pow(2, k + 1, m)) % m
down = pow(2, k, m) - 1
if (x == 0):
    print(0)
else:
    print((up - down) % m)