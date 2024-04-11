n,p=map(int,input().split())
s=input()
ans=s.replace('.','0')
if all(ans[i]==ans[i+p] for i in range(n-p)):
    i=0
    while i<n and s[i]!='.': i+=1
    if i+p<n:
        ans=ans[:i]+'1'+ans[i+1:]
        print(ans)
        exit()
    i=n-1
    while i>=0 and s[i]!='.':i-=1
    if i-p>=0:
        ans=ans[:i]+'1'+ans[i+1:]
        print(ans)        
        exit()
    print("No")
else:
    print(ans)