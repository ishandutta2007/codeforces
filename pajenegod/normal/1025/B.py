import sys
range = xrange

inp = [int(x) for line in sys.stdin for x in line.split()]
ii = 0

n = inp[ii]
ii+=1

vals = []
for _ in range(n):
    a,b = inp[ii],inp[ii+1]
    ii+=2
    if b<a:a,b=b,a
    vals.append((a,b))
vals = sorted(set(vals))

pos_gcd = vals[0]
for _ in range(1,len(vals)):
    A,B = vals[_]
    tmp = []
    for c in pos_gcd:
        C = c
        a = A
        while C:
            a,C=C,a%C
        if a>1:
            tmp.append(a)
        
        a = B
        while c:
            a,c=c,a%c
        if a>1:
            tmp.append(a)
    if _%2==0:
        pos_gcd = tmp
    else:
        pos_gcd = set(tmp)
    #pos_gcd = {gcd(a,c) for c in pos_gcd} | {gcd(b,c) for c in pos_gcd}
    #pos_gcd = set([gcd(a,c) for c in pos_gcd]+[gcd(b,c) for c in pos_gcd])


wcd = max(pos_gcd or [1])
if wcd==1:wcd=-1
print wcd