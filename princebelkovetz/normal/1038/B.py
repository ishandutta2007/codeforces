from sys import stdin, stdout, setrecursionlimit
# plz solve div2c
n = int(input())
if n >= 2 and n % 2 == 1:
    print('Yes')
    print('1', n // 2 + 1)
    print(n - 1, end=' ')
    for i in range(1, n // 2 + 1):
        print(i, end=' ')
        print(n - i + 1, end=' ')
elif n == 1 or n == 2:
    print('No')
else:
    print('Yes')
    x = 0
    if n % 4 != 0:
        x = 1
    print(n // 2 - x, end=' ')
    for i in range(1, n // 4 + 1):
        print(i, end=' ')
        print(n - i + 1, end=' ')
    print()
    print(n // 2 + x, end=' ')
    for i in range (n // 4 + 1, n // 2 + 1):
        print(i, end=' ')
        print(n - i + 1, end=' ')