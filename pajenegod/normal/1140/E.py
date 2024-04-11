from __future__ import print_function
import os,sys,atexit

if sys.version_info[0] < 3:
    range = xrange
    from cStringIO import StringIO as BytesIO
    sys.stdout = BytesIO()
else:
    from io import BytesIO
    sys.stdout = BytesIO()
    _write = sys.stdout.write
    sys.stdout.write = lambda s: _write(s.encode())
atexit.register(lambda: os.write(1, sys.stdout.getvalue()))

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

####

# This code will probably be super slow because of 32 bit python =/


MOD = 998244353

n,k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
Aeven = A[::2]
Aodd = A[1::2]

ways = 1
for A in [Aeven,Aodd]:
    n = len(A)
    i = -1
    while i<n:
        j = i+1
        while j<n and A[j]==-1:j+=1
        
        a = -1
        b = -1
        if i>=0 and A[i]!=-1:
            a = A[i]
            if j<n and A[j]!=-1:
                b = A[j]
        elif j<n and A[j]!=-1:
            a = A[j]

        if b!=-1:
            # Double locked
            val1 = 0
            val2 = 1
            for _ in range(j-i-1):
                val1,val2 = val1*(k-2) + val2, val1*(k-1)
                val1 %= MOD
                val2 %= MOD
            if a==b:
                ways = (k-1)*val1*ways%MOD
            else:
                ways = ((k-2)*val1+val2)*ways%MOD
        elif a!=-1:
            # single locked
            ways = ways*pow(k-1,j-i-1,MOD)%MOD
        else:
            # Not locked
            ways = ways*k*pow(k-1,j-i-1-1,MOD)%MOD
        i = j
print(ways)