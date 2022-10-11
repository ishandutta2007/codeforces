import sys
range = xrange
input = sys.stdin.readline

n,m = [int(x) for x in input().split()]

if m<n:
    m,n = n,m


if n==1:
    err = [0,1,2,3,2,1]
    ans = n*m - err[m%6]
elif n==2 and m<4:
    err = [0,2,4,2]
    ans = n*m - err[m]
elif n==2 and m==7:
    err = 2
    ans = n*m - err
else:
    err = (n*m)%2
    ans = n*m - err

print ans