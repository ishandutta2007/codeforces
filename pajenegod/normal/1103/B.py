import sys
range = xrange
input = raw_input


while input() == 'start':
    count = 0
    x = 1
    while 2*x<=10**9:
        print '?',2*x,x
        count += 1
        sys.stdout.flush()
        if input()=='x':
            x*=2
        else:
            break

    #print '?',0,2*x
    #sys.stdout.flush()
    #if input()=='x':
    #    print '!',2*x
    #    sys.stdout.flush()
    #    continue

    a = 1
    b = x
    while a!=b:
        c = (a+b)//2
        print '?',x+c,x
        sys.stdout.flush()
        count += 1
        if input()=='y':
            b = c
        else:
            a = c+1
    
    if x+a>10**9:
        print '!',1
        sys.stdout.flush()
    else:
        print '!',x+a
        sys.stdout.flush()