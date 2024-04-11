n = input()
n = -n
n %= 360
steps = 0
ans = min(n , 360 - n)
for i in range(1 , 4):
    _n = n + 90 * i
    _s = i
    _n %= 360
    if min(_n , 360 - _n) < ans:
        ans = min(_n , 360 - _n)
        steps = _s
print steps