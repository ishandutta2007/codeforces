s = input()
if len(s) % 2 == 1:
    print(-1)
else:
    l = 0
    r = 0
    u = 0
    d = 0
    for i in s:
        if i == 'U':
            u += 1
        if i == 'D':
            d += 1
        if i == 'L':
            l += 1
        if i == 'R':
            r += 1
    t = min(abs(r - l), abs(u - d))
    print (t + (abs(r - l) - t) // 2 + (abs(u - d) - t) // 2)