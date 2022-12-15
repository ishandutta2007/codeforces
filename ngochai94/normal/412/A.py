x=raw_input().split()
y=raw_input()
n=int(x[0])
k=int(x[1])
if k<=n/2:
    fir='LEFT'
    sec='RIGHT'
    for i in range(k-1):
        print fir
    for i in y[:-1]:
        print 'PRINT',
        print i
        print sec
    print 'PRINT',
    print y[-1]
else:
    fir='RIGHT'
    sec='LEFT'
    for i in range(n-k):
        print fir
    for i in y[:0:-1]:
        print 'PRINT',
        print i
        print sec
    print 'PRINT',
    print y[0]