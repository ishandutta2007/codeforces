import sys
range = xrange
input = sys.stdin.readline

n,k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

if sum(A)%k!=0:
    print 'No'
    sys.exit()

x = sum(A)//k

cur = 0
dum = []
count = 0
for a in A:
    cur += a
    count += 1
    if cur>x:
        print 'No'
        sys.exit()
    if cur==x:
        dum.append(count)
        count = 0
        cur = 0
if len(dum)==k:
    print 'Yes'
    print ' '.join(str(_) for _ in dum)
else:
    print 'No'