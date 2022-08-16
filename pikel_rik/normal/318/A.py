import math as m

s = str(input())
l = s.split()

n = int(l[0])
k = int(l[1])

if k <= m.ceil(n/2):
    print(2*k-1)
else:
    print(2 * (k - m.ceil(n/2)), end = " ")