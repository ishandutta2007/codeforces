for _ in range(1):
    n = int(input())
    s = input()
    cou1 = cou2 = 0
    for x in s:
        if x == '1':
            cou1 += 1
        else:
            cou2 += 1
    if cou1 == cou2 and n != 1:
        print(2)
        print(s[:-1] , s[-1])
    else:
        print(1)
        print(s)