t = int(input().strip())

for i in range(t):
    x, y = map(int, input().split())

    if x > y:
        n = x + y
    elif x < y:
        a, b = x // 2, y // 2
        k = b % a
        p = (b - k) // a
        n = p * x + k
    else:
        n = x

    print (n)
    assert (n % x == y % n)