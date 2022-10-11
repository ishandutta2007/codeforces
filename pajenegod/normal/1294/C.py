import sys
range = xrange
input = raw_input
 
t = int(input())
for _ in range(t):
    n = int(input())
    fac = []
    i = 2
    while i * i <= n:
        while n % i == 0:
            fac.append(i)
            n //= i
        i += 1
    if n > 1:
        fac.append(n)
    
    fac.reverse()
 
    a = fac.pop()
    b = 1
    while b <= a and fac:
        b *= fac.pop()
    c = 1
    while (c <= a or c == b) and fac:
        c *= fac.pop()
    
    if a > 1 and b > 1 and c > 1 and a != b and a != c and b != c:
        a,b,c = sorted((a,b,c))
        for f in fac:
            c *= f
        print 'YES'
        print a,b,c
    else:
        print 'NO'