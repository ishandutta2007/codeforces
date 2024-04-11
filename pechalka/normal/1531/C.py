n = int(input())
if n == 2:
    print(-1)
    exit(0)

k = 1
while (k + 1) * (k + 1) <= n:
    k += 1

if k * k == n:
    print(k)
    for i in range(k):
        print('o' * k)
    exit(0)

n -= k * k
if n == 2 * k - 1:
    print(k + 2)
    print('o' + '.' * (k + 1))
    for i in range(k):
        if i < 2:
            print('o' * (k - 1) + '.' * 3)
        else:
            print('o' * (k + 1) + '.')
    print('o' * (k + 2))
elif n % 2 == 0:
    n //= 2
    print(k + 1)
    print('o' * n + '.' * (k + 1 - n))
    for i in range(k):
        if i >= k - n:
            print('o' * (k + 1))
        else:
            print('o' * k + '.')
else:
    n = (n + 1) // 2
    print(k + 1)
    print('o' * n + '.' * (k + 1 - n))
    for i in range(k):
        if i == 0:
            print('o' * (k - 1) + '.', end='')
        else:
            print('o' * k, end='')
        if i >= k - n:
            print('o')
        else:
            print('.')