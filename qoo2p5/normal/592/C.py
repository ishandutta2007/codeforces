gcd = lambda x, y: gcd(y, x % y) if y != 0 else x
nok = lambda x, y: x * y // gcd(x, y)


def print_fraction(x, y):
    print(str(x // gcd(x, y)) + '/' + str(y // gcd(x, y)))


t, w, b = map(int, input().split())

g = nok(w, b)
p = min(w, b)
if p - 1 >= t:
    print_fraction(1, 1)
else:
    n = (t + 1 - p) // g
    ans = p + n * p + max(0, t + 1 - g * (n + 1))
    print_fraction(ans - 1, t)