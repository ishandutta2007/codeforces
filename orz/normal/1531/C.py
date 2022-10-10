n = int(input())
if n == 2:
    print(-1)
else:
    k = 1 + int((n - 1) ** .5)
    e = k * k - n
    if e == 0:
        print(k)
        for i in range(k):
            print('o' * k)
    elif e == 2:
        print(k + 1)
        print('o' + '.' * k)
        for i in range(2):
            print('o' * (k - 2) + '.' * 3)
        for i in range(k - 3):
            print('o' * k + '.')
        print('o' * (k + 1))
    else:
        print(k)
        f = (e + 1) // 2
        print('o' * (k - f) + '.' * f)
        if e % 2 == 0:
            print('o' * (k - 2) + '.' * 2)
        for i in range(e // 2 - (e + 1) % 2 * 2):
            print('o' * (k - 1) + '.')
        for i in range(k - f):
            print('o' * k)