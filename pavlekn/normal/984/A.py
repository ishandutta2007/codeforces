n = int(input())
a = sorted(list(map(int, input().split())))
if (n % 2 == 1):
    print(a[n // 2])
else:
    print(a[n // 2 - 1])