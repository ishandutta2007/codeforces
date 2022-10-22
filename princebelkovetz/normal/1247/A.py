n, m = map(int, input().split())
if n == m - 1:
    print(n, m)
elif n == m:
    print(str(n) + '1 ' + str(m) + '2')
elif m - n >= 2:
    print(-1)
elif n == 9 and m == 1:
    print("9 10")
else:
    print(-1)