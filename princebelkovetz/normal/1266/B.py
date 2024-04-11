for _ in range(1):
    n = input()
    a = [int(i) for i in input().split()]
    for x in a:
        if x >= 15 and 1 <= x % 14 <= 6:
            print('YES')
        else:
            print('NO')