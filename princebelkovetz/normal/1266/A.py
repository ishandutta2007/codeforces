for _ in range(int(input())):
    n = input()
    s = cou = 0
    f = False

    for x in str(n):
        s += int(x)
        if int(x) == 0:
            f = True
        if int(x) % 2 == 0:
            cou += 1

    if f and s % 3 == 0 and cou > 1:
        print('red')
    else:
        print('cyan')