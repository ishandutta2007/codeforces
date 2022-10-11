import sys
range = xrange
input = raw_input

t = int(input())
out = []
for _ in range(t):
    a,b,c,n = [int(x) for x in input().split()]
    s = a + b + c + n
    if s%3 != 0:
        out.append('NO')
    else:
        x = s // 3
        if x >= a and x >= b and x >= c:
            out.append('YES')
        else:
            out.append('NO')

print '\n'.join(out)