k, n = map(int, input().split())
a = list(map(int, input().split()))
count = 0
ans = 1
for i in range(n):
    if (k // a[i] * a[i] > count):
        count = k // a[i] * a[i]
        ans = i + 1
print(ans, count // a[ans - 1])