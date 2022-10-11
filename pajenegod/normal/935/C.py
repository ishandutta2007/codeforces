import sys
range = xrange
input = raw_input

R,x1,y1,x2,y2 = [int(x) for x in input().split()]


if x1==x2 and y1==y2:
    y3 = y1
    x3 = x1+float(R)/2
    r = float(R)/2
    print '%.16f' % x3,'%.16f' % y3,'%.16f' % r
    sys.exit()


if (x1-x2)**2+(y1-y2)**2>R**2:
    x3 = x1
    y3 = y1
    r = R
    print '%.16f' % x3,'%.16f' % y3,'%.16f' % r
    sys.exit()

rand_pos = (-float(x2-x1),-float(y2-y1))
d = (rand_pos[0]**2 + rand_pos[1]**2)**0.5
rand_pos = (R*rand_pos[0]/d,R*rand_pos[1]/d)

x3 = x1 + float(x2-x1+rand_pos[0])/2
y3 = y1 + float(y2-y1+rand_pos[1])/2
r = ((x2-x3)**2 + (y2-y3)**2)**0.5


print '%.16f' % x3,'%.16f' % y3,'%.16f' % r