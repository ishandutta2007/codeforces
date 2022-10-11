import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]

for _ in range(k):
    if n%10!=0:
        n-=1
    else:
        n//=10
print n