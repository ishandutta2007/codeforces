n=input()
a=[-1]*100001
ans=True
for i in range(n):
    t=raw_input().split()
    x=int(t[0])
    k=int(t[1])
    if a[k]>=x-1:
        a[k]=max(a[k],x)
    else:
        ans=False
        break
if ans:
    print 'YES'
else:
    print 'NO'