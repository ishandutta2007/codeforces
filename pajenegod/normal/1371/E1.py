import sys
range = xrange
input = raw_input

n,p = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
A.sort()
y = max([A[i] - i for i in range(n)])

l = y - 1
r = y + 10 ** 6
while l < r:
    x = l + r + 1 >> 1

    ways = [0] * n
    for a in A:
        b = a - x
        if b < 0:
            ways[0] += 1
        else:
            ways[b] += 1
    for i in range(n - 1):
        ways[i + 1] += max(0, ways[i] - 1)
    
    if any(w >= p for w in ways):
        r = x - 1
    else:
        l = x

ans0 = y
ans1 = r + 1
print ans1 - ans0
print ' '.join(str(x) for x in range(ans0, ans1))