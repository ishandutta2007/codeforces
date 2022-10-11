
import sys
range = xrange
input = raw_input

inter = lambda: int(input())
inters = lambda: [int(x) for x in input().split()]

t = inter()
for _ in range(t):
    n,k = inters()
    
    best = 1
    i = 1
    while i * i <= n:
        if n % i == 0:
            x1 = n // i
            x2 = n // x1
            if best < x1 <= k:
                best = x1
            if best < x2 <= k:
                best = x2
        i += 1
    print n // best