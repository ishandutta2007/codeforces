n, w = map(int, input().split())
a = list(map(int, input().split()))
b = []
b.append(a[0])
for i in range(1, n):
    b.append(b[-1] + a[i])
l = min(b)
r = max(b)
left = 0
right = w
if (l < 0):
    left -= l
if (r > 0):
    right -= r
print(max(0, right - left + 1))