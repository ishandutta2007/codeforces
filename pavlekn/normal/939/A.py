n = int(input())
a = list(map(int, input().split()))
l = False
for i in range(n):
    if (a[i] - 1 != i and i != a[a[i] - 1] - 1 and i == a[a[a[i] - 1] - 1] - 1):
        l = True
if (l):
    print("YES")
else:
    print("NO")