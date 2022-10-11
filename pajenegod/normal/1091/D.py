import itertools
range = xrange
input = raw_input

n = int(input())

MOD = 998244353  

cursum = 0
for i in range(2,n+1):
    cursum = (cursum + (cursum + i)*(i-1))%MOD

nfac = 1
for j in range(1,n+1):
    nfac = nfac*j%MOD



val = nfac + n*(nfac-1)-cursum
print val%MOD