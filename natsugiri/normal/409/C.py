import sys
a = list(map(int, sys.stdin.readline().split()))
d = [1, 1, 2, 7, 4]
ans = a[0]
for i in range(5):
    ans = min(ans, a[i] // d[i])
print(ans)