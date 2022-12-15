n,m=map(int,raw_input().split())
ans=n/2+n%2
if ans%m==0:
    print ans
else:
    ans=ans+m-ans%m
    if ans<=n:
        print ans
    else:
        print -1