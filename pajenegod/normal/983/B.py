import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]
q = int(input())

f = [0]*(n*n)
for l in range(n):
    f[l+n*l]=A[l]

for length in range(2,n+1):
    for l in range(n-length+1):
        r = l+length-1
        f[l+n*r] = f[l+1+n*r]^f[l+n*(r-1)]

DP = [0]*(n*n)        
for l in range(n):
    DP[l+n*l]=A[l]

for length in range(2,n+1):
    for l in range(n-length+1):
        r = l+length-1
        DP[l+n*r] = max(f[l+n*r],DP[l+1+n*r],DP[l+n*(r-1)])

inp = [int(x)-1 for line in sys.stdin for x in line.split()]
ii = 0
out = []
for _ in range(q):
    l,r = inp[ii],inp[ii+1]
    ii+=2

    out.append(DP[l+n*r])
print '\n'.join([str(x) for x in out])