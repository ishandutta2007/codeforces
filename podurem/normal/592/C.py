def gcd(a, b) :
    if (a % b == 0) :
        return b
    else :
        return gcd(b, a % b)

x, b, w = map(int, input().split())
cop = b * w // gcd(b, w)
kol = min(b, w) - 1 + (x // cop - 1) * min(b, w) + min(x - (x // cop) * cop + 1, min(b, w))
ch = gcd(kol, x)
print(int(kol // ch), "/", int(x // ch), sep = '')