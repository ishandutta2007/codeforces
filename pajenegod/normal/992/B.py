import sys
range = xrange
input = sys.stdin.readline

def gcd(a,b):
    while b:a,b=b,a%b
    return a


big = 10**5
P = [True]*big
P[0]=False
P[1]=False

for i in range(big):
    if P[i]:
        j = i*i
        while j<big:
            P[j]=False
            j+=i

P = [p for p in range(big) if P[p]]

l,r,x,y = [int(x) for x in input().split()]

Y = y


div = {1}
for p in P:
    while y%p==0:
        y//=p
        div |= {f*p for f in div}
        
if y!=1:
    div |= {f*y for f in div}

pair = 0
for a in div:
    b = Y//a
    if b%x==0 and gcd(a,b//x)==1 and l<=a*x<=r and l<=b<=r:
        pair += 1

print pair