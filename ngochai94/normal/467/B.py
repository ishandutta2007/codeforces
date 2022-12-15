n,m,k=map(int,raw_input().split())
ans=0
lis=[]
for i in range(m+1):
    lis.append(input())
fe=lis[-1]
for i in range(m):
    d=lis[i]^fe
    if bin(d).count('1')<=k:
        ans+=1
print ans