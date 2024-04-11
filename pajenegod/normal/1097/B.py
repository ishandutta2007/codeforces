import sys
range = xrange
input = raw_input

n = int(input())
A = [int(input()) for _ in range(n)]

for i in range(2**n):
    s = 0
    for a in A:
        if i%2==1:
            s+=a
        else:
            s-=a
        i//=2
    if s%360==0:
        print 'YES'
        sys.exit()
print 'NO'