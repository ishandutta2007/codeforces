a,b,c=map(int,input().split())
l=sorted(list(map(int,input().split())))
if b>c:
    sums=sum(l)
    if 10**100*(b-c)>sums:
        print(a)
    else:
        for i in l[::-1]:
            if sums-i>10**100*(b-c):
                sums-=i
                a-=1
            else:
                print(a-1)
                break
else:
    cnt=0
    for i in l:
        if i<=b:
            cnt+=1
    if cnt%2==0:
        print(cnt//2)
    else:
        print(cnt//2+1)