from sys import stdout
 
def ask(l, r):
    if l == r:
        return -1
    print('?', l, r)
    stdout.flush()
    return int(input())
 
n = int(input())
smax = ask(1, n)
if smax == 1 or ask(1, smax) != smax:
    l = smax
    r = n
    while r - l > 1:
        mid = (l + r) // 2
        if ask(smax, mid) == smax:
            r = mid
        else:
            l = mid
    print('!', r)
else:
    l = 1
    r = smax
    while r - l > 1:
        mid = (l + r) // 2
        if ask(mid, smax) == smax:
            l = mid
        else:
            r = mid
    print('!', l)
stdout.flush()