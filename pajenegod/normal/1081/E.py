import sys
import math
range = xrange
input = sys.stdin.readline

n = int(input())
X = [int(x) for x in input().split()]

for x in X:
    if x%2==0 and (x//2)%2!=0:
        print 'No'
        sys.exit()

roots = []
c = 0
for x in X:
    p = int(c+(x+c**2)**0.5)+1
    while p<=x and (x%p!=0 or (p+x//p)%2==1):
        p+=1
     
    if p>x:
        print 'No'
        sys.exit()

    b = (p + x//p)//2
    a = (p - x//p)//2
    if b<=a or (roots and a <= roots[-1]) or a<=0:
        print 'No'
        sys.exit()
    roots.append(a)
    roots.append(b)
    c = b

out = [roots[0]**2]
for i in range(n-1):
    out.append(roots[i+1]**2-roots[i]**2)
print 'Yes'
print ' '.join(str(x) for x in out)