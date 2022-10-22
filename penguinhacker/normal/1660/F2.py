t=int(input())
for _ in range(t):
    n=int(input())
    s=input()
    
    cnt=[0]*(2*n+1)
    last=[0]*(2*n+1)
    cur=[0]*3
    
    cnt[n]=1
    last[n]=1
    cur[n%3]=1
    
    depth=n
    ans=0
    
    for i in range(n):
        if s[i]=='+':
            cur[depth%3]-=last[depth]
            last[depth]=0

        depth+=(1 if s[i]=='+' else -1)
        
        cur[depth%3]+=cnt[depth]-last[depth]
        last[depth]=cnt[depth]
        ans+=cur[depth%3]
        
        cnt[depth]+=1
        cur[depth%3]+=1
        last[depth]=cnt[depth]
    print(ans)