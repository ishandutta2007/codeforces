import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    d, k = [int(x) for x in input().split()]
    

    i = 0.0
    d2 = d * d / 2.0
    kf = float(k)
    while (i + kf) ** 2 <= d2:
        i += k
    i = int(i)

    print 'Ashish' if i ** 2 + (i + k) ** 2 <= d ** 2 else 'Utkarsh'