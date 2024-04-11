x,sums=map(int,input().split())
mxs=[]
mns=[]
for i in range(x):
    a,b=map(int,input().split())
    mns+=[a]
    mxs+=[b]
if sum(mxs)<sums or sum(mns)>sums:
    print("NO")
else:
    l=[]
    b=0
    b+=sums
    sums=0
    for i in mns:
        l+=[i]
        sums+=i
    for i in range(x):
        sums-=l[i]
        l[i]=mxs[i]
        sums+=mxs[i]
        if sums==b:
            break
        elif sums>b:
            l[i]-=sums-b
            break
    print("YES")
    print(*l)