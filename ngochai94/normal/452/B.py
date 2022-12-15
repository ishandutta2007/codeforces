n,m=map(int,raw_input().split())
if n==0:
    print 0,1
    print 0,m
    print 0,0
    print 0,m-1
elif m==0:
    print 1,0
    print n,0
    print 0,0
    print n-1,0
elif m>=n:
    if 2*(m**2+(n-1)**2)**0.5>=m+(m**2+n**2)**0.5:
        print 1,0
        print n,m
        print 0,0
        print n-1,m
    else:
        print n,m
        print 0,0
        print 0,m
        print n,0
else:
    if 2*((m-1)**2+n**2)**0.5>=n+(m**2+n**2)**0.5:
        print 0,1
        print n,m
        print 0,0
        print n,m-1
    else:
        print n,m
        print 0,0
        print n,0
        print 0,m