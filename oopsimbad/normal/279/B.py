n, t = map(int, input().split())
a = [int(x) for x in input().split()]

l, r = 0,0
sum = 0
ans = 0
while l < n:
    if sum <= t and r < n:
        sum += a[r]
        r += 1
    else:
        sum -= a[l]
        l += 1

    if sum <= t:
        ans = max(ans, r-l)
print(ans)