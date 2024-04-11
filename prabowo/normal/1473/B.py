from math import gcd


def divisors(s):
    ret = set()
    for i in range(1, len(s) + 1):
        if len(s) % i:
            continue
        if s[:i] * (len(s) // i) == s:
            ret.add(s[:i])
    return ret


for tc in range(int(input())):
    s = input()
    t = input()
    divs = divisors(s).intersection(divisors(t))
    if not divs:
        print(-1)
    else:
        g = ''
        for d in divs:
            if len(d) > len(g):
                g = d
        ans = g * (((len(s) * len(t)) // len(g)) // len(g))
        print(ans)