n,m=map(int,input().split())
l,r=0,n
mins=999999999999
while abs(l-r)!=1:
    mid=(l+r)//2
    cnt=0
    mid_copy=mid
    while mid>=1:
        cnt+=mid
        mid//=m
    if n<=cnt:
        mins=min(mins,mid_copy)
        r=mid_copy
        continue
    if n==cnt:
        print(min_copy)
        break
    if cnt>n:
        r=mid_copy
    else:
        l=mid_copy
else:
    if m>n:
        print(n)
    else:
        mid=(l+r)//2
        cnt=0
        mid_copy=mid
        while mid>=1:
            cnt+=mid
            mid//=m
        if n<=cnt:
            mins=min(mins,mid_copy)
            r=mid_copy
        if n==cnt:
            print(mid_copy)
        else:
            print(mins)