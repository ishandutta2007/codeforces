n,white,black=map(int,input().split())
l=list(map(int,input().split()))
r=n-1
ls=0
cnt=0
while r>=ls:
    if r==ls:
        if l[r]!=1 and l[ls]!=0:
            cnt+=min(white,black)
        r-=1
        ls+=1
        continue
    if l[ls]==2:
        if l[r]==0:
            cnt+=white
        elif l[r]==1:
            cnt+=black
        else:
            cnt+=min(white,black)*2
    elif l[ls]==1:
        if l[r]==2:
            cnt+=black
        elif l[r]==1:
            pass
        else:
            print(-1)
            break
    else:
        if l[r]==2:
            cnt+=white
        elif l[r]==0:
            pass
        else:
            print(-1)
            break
    r-=1
    ls+=1
else:
    print(cnt)