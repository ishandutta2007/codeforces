n = input()
p = n + n - 2
l = 1
r = n
ans = 0
while r <= p:
    tmp = 4
    if l > 1:
        tmp *= 3
        tmp *= pow(4 , l - 2)
    if r < p:
        tmp *= 3
        tmp *= pow(4 , p - r - 1)
    l += 1
    r += 1
    ans += tmp
print ans