n,s=map(int,input().split())
l=[[] for i in range(n+1)]
for i in range(n-1):
    ls,r=map(int,input().split())
    l[r]+=[1]
    l[ls]+=[1]
cnt=0
for i in range(1,len(l)):
    if len(l[i])==1:
        cnt+=1
print(s/cnt*2)