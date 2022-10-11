import sys,__pypy__,os
range = xrange
input = raw_input

n,k,s = [int(x) for x in input().split()]

out = __pypy__.builders.StringBuilder()
if k<=s<=(n-1)*k:
    out.append('YES\n')
    di = 1
    pos = 1
    while s>0:
        mv = di*min(n-1,s-k+1)
        s -= di*mv
        k -= 1
        di *= -1
        pos += mv
        out.append(str(pos))
        out.append(' ')
else:
    out.append('NO\n')
os.write(1,out.build())