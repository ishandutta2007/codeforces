from math import ceil

for _ in range(int(input())):
    l, r, m = map(int, input().split())
    ok1 = m + r - l
    for i in range(l, r + 1):
        ok2 = ok1 % i
        if ok2 <= (r - l) * 2:
            print(i, end=" ")
            ok2 -= (r - l)
            if ok2 >= 0:
                print(r, r - ok2)
            else:
                print(l, l - ok2)
            break