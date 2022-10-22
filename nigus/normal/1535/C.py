import math
T=int(input())
for _ in range(T):
    s=input()
    n=len(s)
    mm=-1
    ans=0
    par=[-1,-1]
    last=[-1,-1]
    for i in range(0, n):
        if s[i]!='?':
            p = (int(s[i])+i)%2
            last[p]=i
            par[p]=last[p^1]
        mm=max(par[0],par[1])
        ans+=i-mm
    print(ans)