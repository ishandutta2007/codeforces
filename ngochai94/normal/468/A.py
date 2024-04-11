n=input()
if n==1 or n==2 or n==3:
    print 'NO'
else:
    print 'YES'
    if n==4:
        print '1 * 2 = 2'
        print '2 * 3 = 6'
        print '6 * 4 = 24'
    elif n==5:
        print '1 * 2 = 2'
        print '3 - 2 = 1'
        print '5 + 1 = 6'
        print '6 * 4 = 24'
    elif n%4==2:
        print '4 * 6 = 24'
        print '2 * 1 = 2'
        print '2 + 3 = 5'
        print '5 - 5 = 0'
        print '24 + 0 =24'
    elif n%4==3:
        print '7 + 2 = 9'
        print '9 - 1 = 8'
        print '8 - 3 = 5'
        print '5 - 5 = 0'
        print '4 * 6 = 24'
        print '24 + 0 = 24'
    elif n%4==0:
        print '4 * 6 = 24'
        print '8 + 5 = 13'
        print '13 - 7 = 6'
        print '6 - 1 = 5'
        print '5 - 2 = 3'
        print '3 - 3 = 0'
        print '24 + 0 = 24'
    else:
        print '7 + 8 = 15'
        print '15 - 9 = 6'
        print '6 - 5 = 1'
        print '1 * 1 = 1'
        print '1 + 2 = 3'
        print '3 - 3 = 0'
        print '4 * 6 = 24'
        print '24 - 0 = 24'
    st=6+(n+2)%4
    remain = (n-st)/4
    for i in range(remain):
        print '24 +',str(st+1+i*4),'=',str(24+st+1+i*4)
        print  str(24+st+1+i*4),'-',str(st+2+i*4),'=','23'
        print '23 -',str(st+3+i*4),'=',str(20-st-i*4)
        print str(20-st-i*4),'+',str(st+4+i*4),'=','24'