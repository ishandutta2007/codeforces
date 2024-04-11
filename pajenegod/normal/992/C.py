import sys
range = xrange
input = sys.stdin.readline

mod = 10**9+7
x,k = [int(x) for x in input().split()]

if x==0:
    print 0
    sys.exit()


ans = x*pow(2,k+1,mod)

#for m in range(k):
#    ans -= pow(2,m,mod)

ans -= (1-pow(2,k,mod))*pow(1-2,mod-2,mod)

print ans%mod