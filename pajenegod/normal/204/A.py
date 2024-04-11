import sys
range = xrange
input = raw_input

l,r = [int(x) for x in input().split()]


def ans(r):
    while str(r)[-1] != str(r)[0]:
        r -= 1
    
    if r < 10:
        return r + 1
    
    d = 0
    while (r//10**d) >= 10:
        d += 1

    maxr = r // 10**d
    rest = (r - maxr * 10**d) / 10 + 1

    r -= maxr * 10**d
    return ans(maxr * 10**d - 1) + rest

print ans(r) - ans(l - 1)