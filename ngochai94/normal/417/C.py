a=raw_input().split()
n=int(a[0])
k=int(a[1])
if 2*k>n-1:
    print -1
else:
    print n*k
    for i in range(1,n+1):
        for t in range(1,k+1):
            print i, (i+t-1)%n+1