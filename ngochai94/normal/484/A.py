for _ in range(input()):
    l,r=map(int,raw_input().split())
    s=bin(r)[2:]
    if s.count('0')==0:
        print r
        continue
    n=len(s)-1
    ans=0
    for i in range(n,-1,-1):
        if (l&(1<<i))==0 and (r&(1<<i))!=0:
                break
        ans+=(1<<i)*min(1,(l&(1<<i)))
    if s[-i-1:].count('0')==0:
        ans+=(1<<i)
        if (l&1)==1 and (r&1)==1 and i==0:
            ans-=1
    for j in range(i-1,-1,-1):
        ans+=(1<<j)
    print ans