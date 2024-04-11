n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
if (k == 0):
    if (a[0] == 1):
        print(-1)
    else:
        print(1)
else:
    k -= 1
    if (k < n - 1 and a[k] == a[k + 1]):
        print(-1)
    else:
        print(a[k])