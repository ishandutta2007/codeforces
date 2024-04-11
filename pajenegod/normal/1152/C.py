import sys
range = xrange
input = raw_input

def gcd(a,b):
    while b:
        a,b = b,a%b
    return a

a,b = [int(x) for x in input().split()]

if a>=b:
    a,b = b,a

c = b-a
if c==0:
    print 0
    sys.exit()


besta = (a//gcd(a,b)*b,0)
x = 0
while x*x<=c:
    if x and c%x==0:
        k = (x-a)%x
        lcm = (a+k)//gcd(a+k,b+k)*(b+k)
        besta = min(besta, (lcm,k))
    
        X = c//x
        k = (X-a)%X
        lcm = (a+k)//gcd(a+k,b+k)*(b+k)
        besta = min(besta, (lcm,k))
    x += 1
print besta[1]