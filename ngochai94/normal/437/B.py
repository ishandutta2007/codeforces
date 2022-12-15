s,l=map(int,raw_input().split())
lis=[]
i=0
while True:
    k=(l/2**i+1)/2
    if k!=0:
        lis.append(k)
    else:
        break
    i+=1
ans=[0]*len(lis)
k=len(lis)-1
while k!=-1 and s!=0:
    if s>=2**k:
        if lis[k]!=0:
            lis[k]-=1
            s-=2**k
            ans[k]+=1
        else:
            k-=1
    else:
        k-=1
if k==-1:
    print -1
else:
    print sum(ans)
    for i in range(len(ans)):
        for k in range(ans[i]):
            print 2**i+2**(i+1)*k,