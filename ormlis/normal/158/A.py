n, k = map(int, input().split())
a = list(map(int, input().split()))
e = max(a[k - 1], 1)
c = 0
for i in a:
    if i >= e:
        c += 1
print(c)