t=int(input())
for _ in range(t):
    s=input().strip()
    seen=[False]*26
    ans=len(s)
    for i in s:
        x=ord(i)-ord('a')
        if seen[x]:
            ans-=2
            for j in range(26):
                seen[j]=False
        else:
            seen[x]=True
    print(ans)