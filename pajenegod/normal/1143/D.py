def gcd(x, y):
    """ greatest common divisor of x and y """
    while y:
        x, y = y, x%y
    return x

n, k = [int(x) for x in input().split()]
nk = n*k
a, b = [int(x) for x in input().split()]

mini = gcd(nk, (a+b)%k)
maxi = gcd(nk, (a+b)%k)

for li in [(a + b) % k, (max(a,b) - min(a,b)) % k]:
    while li < nk:
        res = gcd(nk, li)
        if res < mini:
            mini = res
        elif res > maxi:
            maxi = res
        li += k

print(*[nk//maxi, nk//mini])