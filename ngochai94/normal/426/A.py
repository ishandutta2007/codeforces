x=raw_input().split()
n=int(x[0])
s=int(x[1])
lis=raw_input().split()
for i in range(len(lis)):
    lis[i]=int(lis[i])
k=sum(lis)-max(lis)
if s<k:
    print 'NO'
else:
    print 'YES'