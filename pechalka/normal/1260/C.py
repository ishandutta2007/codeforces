def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

n = int(input())
for i in range(n):
    r, b, k = map(int, input().split())
    if b > r:
        r, b = b, r
    r, b = r // gcd(r, b), b // gcd(r, b)
    if (r + b - 2) // b >= k:
        print("REBEL")
    else:
        print("OBEY")