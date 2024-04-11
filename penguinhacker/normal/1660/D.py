t=int(input())
for _ in range(t):
    n=int(input())
    a=[int(i) for i in input().split()]
    ans=[0, 0, n]
    dp=[[0, 0], [696969, -1]]
    sign, cur=0, 0
    for i in range(n):
        if a[i]==0:
            dp=[[0, i+1], [696969, -1]]
            sign, cur=0, 0
            continue
        cur+=1 if abs(a[i])==2 else 0
        if a[i]<0:
            sign^=1
        ans=max(ans, [cur-dp[sign][0], dp[sign][1], n-i-1])
        dp[sign]=min(dp[sign], [cur, i+1])
    print(str(ans[1])+' '+str(ans[2]))