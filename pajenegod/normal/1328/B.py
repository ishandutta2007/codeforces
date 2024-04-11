import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n, k = [int(x) for x in input().split()]
    k -= 1

    a = 1
    b = 0
    while k:
        dk = min(a - b, k)
        b += dk
        k -= dk
        if b == a:
            a += 1
            b = 0

    ans = ['a']*n
    ans[~a] = 'b'
    ans[~b] = 'b'
    print ''.join(ans)