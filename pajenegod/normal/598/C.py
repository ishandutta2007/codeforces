import sys
from math import atan2
from fractions import Fraction
range = xrange

inp = [int(x) for x in sys.stdin.read().split()]
ind = 0

n = inp[ind]
ind += 1

X = inp[ind:2*n+ind:2]
Y = inp[ind+1:2*n+ind:2]
ind += 2*n


sign = lambda x: 1 if x>=0 else -1

# Sort using floating point numbers
#def anglesort(index):
#    return sorted(index, key=lambda i: atan2(Y[i],X[i]))

# Sort using integers
def anglesort(index):
    halves = [[] for _ in range(2)]
    for i in index:
        x,y = X[i],Y[i]
        halves[y>=0].append(i)

    for j in range(2):
        # Sort the point with respect to cos(angle)*abs(cos(angle))
        # where angle is the angle between (1,0) and (X[i],Y[i])
        halves[j].sort(key=lambda i:sign(X[i])*Fraction(X[i]**2,X[i]**2 + Y[i]**2),reverse=True)
    return halves[0] + halves[1][::-1]


order = anglesort(range(n))
order.append(order[0])

besta = -2
best_ = None
for _ in range(n):
    i = order[_]
    j = order[_+1]
    
    # cos2 is cos(angle)*abs(cos(angle))
    # where angle is the angle between (X[i],Y[i]) and (X[j],Y[j])
    cos2 = sign(X[i]*X[j] + Y[i]*Y[j])*Fraction((X[i]*X[j] + Y[i]*Y[j])**2,(X[i]**2 + Y[i]**2) * (X[j]**2 + Y[j]**2))
    if cos2>besta:
        besta = cos2
        best_ = _
print order[best_]+1,order[best_+1]+1