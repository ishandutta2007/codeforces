n,m,k=map(int,raw_input().split())
ans=[0]*m
for i in range(n):
    x=raw_input()
    for k in range(m):
        if x[k]=='U' and i%2==0:
            ans[k]+=1
        elif x[k]=='L' and k>=i:
            ans[k-i]+=1
        elif x[k]=='R' and k+i<m:
            ans[k+i]+=1
print ' '.join(map(str,ans))