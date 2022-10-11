import sys
range = xrange
input = raw_input

def gcd(a,b):
    while b:
        b,a = a%b,b
    return a

n,l,x,y = [int(_) for _ in input().split()]
A = [int(_) for _ in input().split()]

posx = []
posy = []
for a in A:
    if a - x >= 0:
        posx.append(a - x)
    if a + x <= l:
        posx.append(a + x)
    if a - y >= 0:
        posy.append(a - y)
    if a + y <= l:
        posy.append(a + y)

if set(A) & set(posx):
    if set(A) & set(posy):
        print 0
        sys.exit()
    else:
        print 1
        print posy[0]
        sys.exit()

if set(A) & set(posy):
    print 1
    print posx[0]
    sys.exit()

B = list(set(posx) & set(posy))
if B:
    print 1
    print B[0]
    sys.exit()

print 2
print x, y