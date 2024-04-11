t=int(input())
for _ in range(t):
    n=int(input())
    s=input()
    cnt=[0]*(2*n+1)
    depth=n
    cnt[n]+=1
    ans=0
    for c in s:
        depth+=1 if c=='+' else -1
        for i in range(depth, 2*n+1, 3):
            ans+=cnt[i]
        cnt[depth]+=1
    print(ans)