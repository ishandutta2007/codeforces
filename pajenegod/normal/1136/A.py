import sys
range = xrange
input = raw_input

n = int(input())

inp = [int(x) for x in sys.stdin.read().split()]
L = inp[:2*n:2]
R = inp[1:2*n:2]
k = inp[-1]

i = 0
k-=1
while k>=0:
    if i<n:
        k-=(R[i]-L[i]+1)
    else:
        k=-1
    i+=1
print n-(i-1)