n, k = map(int, input().split())
a = [int(i) for i in input().split()]
l = 1
r = n + 1
while r - l > 1:
    mid = (r + l) // 2
    b = [1 if i >= mid else -1 for i in a]
    for i in range(1, len(b)):
        b[i] += b[i - 1]
    ans = False
    if b[k - 1] > 0:
        ans = True
    mn = 0
    for i in range(k, len(b)):
        mn = min(mn, b[i - k])
        if b[i] - mn > 0:
            ans = True
    if ans:
        l = mid
    else:
        r = mid
print(l)