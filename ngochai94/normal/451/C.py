def test(n,k,d1,d2):
    f=min(0,d2,d1+d2)
    if k<2*d2+d1-3*f:
        return False
    if (k-d1-2*d2)%3!=0:
        return False
    r=n-k
    if (r+d1-d2)%3!=0:
        return False
    if min(r+d1-d2,r-d2-2*d1,r+d1+2*d2)<0:
        return False
    return True
for _ in range(input()):
    n,k,d1,d2=map(int,raw_input().split())
    if test(n,k,d1,d2):
        print 'yes'
    elif test(n,k,-d1,d2):
        print 'yes'
    elif test(n,k,-d1,-d2):
        print 'yes'
    elif test(n,k,d1,-d2):
        print 'yes'
    else:
        print 'no'