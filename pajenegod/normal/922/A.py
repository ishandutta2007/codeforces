import sys
input = raw_input
range= xrange
x,y = [int(a) for a in input().split()]

if y==0:
    print 'No'
    sys.exit()
cop = y-1

if cop==0 and x!=0:
    print 'No'
    sys.exit()

if cop>x:
    print 'No'
    sys.exit()

if (x-cop)%2==0:
    print 'Yes'
else:
    print 'No'