t=int(input())
ans=[]
for i in range(t):
    n,s,k=input().split()
    n=int(n)
    s=int(s)
    k=int(k)
    cl=[int(i) for i in input().split()]
    if s not in cl:
        ans.append(0)
    else:
        for j in range(1,n):
            if s+j not in cl and s+j<=n:
                ans.append(j)
                break
            elif s-j not in cl and s-j>=1:
                ans.append(j)
                break
for i in range(t):
    print(ans[i])