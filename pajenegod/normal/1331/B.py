import sys
range = xrange
input = raw_input

n = int(input())
ans = []

p = 2
while n > 1:
    while n % p == 0:
        ans.append(p)
        n //= p
    p += 1

print ''.join(str(x) for x in ans)