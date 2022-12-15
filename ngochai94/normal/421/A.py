x=raw_input().split()
n=int(x[0])
a=int(x[1])
b=int(x[2])
lisa=raw_input().split()
lisb=raw_input().split()
for i in range(1,n+1):
    if str(i) in lisa:
        print 1,
    else:
        print 2,