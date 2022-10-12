n, a, r, m = [int(s) for s in input().split()]
h = sorted([int(s) for s in input().split()])

add, rem = 0, sum(h) - min(h) * n
ans, cur = rem * r, rem * r
for i in range(1, n):
    dadd, drem = i, -(n-i)
    dcost, dh = dadd * min(m, a + r) + (drem - dadd) * r, h[i] - h[i-1]
    if add <= rem and add + dadd*dh > rem + drem*dh:
        rdh = (rem - add) // (dadd - drem)
        ans = min(ans, cur + rdh * dcost)
    cur, add, rem = cur + dcost*dh, add + dadd*dh, rem + drem*dh
    if add <= rem:
        ans = min(ans, cur)

cur = add * a
ans = min(ans, cur)
for i in range(n-1, 0, -1):
    dadd, drem = -i, n-i
    dcost, dh = drem * min(m, a + r) + (dadd - drem) * a, h[i] - h[i-1]
    if add >= rem and add + dadd*dh < rem + drem*dh:
        rdh = (add - rem) // (drem - dadd)
        ans = min(ans, cur + rdh * dcost)
    cur, add, rem = cur + dcost*dh, add + dadd*dh, rem + drem*dh
    if add >= rem:
        ans = min(ans, cur)

print(ans)