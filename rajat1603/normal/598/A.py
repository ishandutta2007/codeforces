t = input()
while t:
    t -= 1
    n = input()
    ans = n * (n + 1) / 2
    cur = 1
    while cur <= n:
        cur *= 2
        ans -= cur
    print ans