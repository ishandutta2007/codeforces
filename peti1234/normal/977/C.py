n,k=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
if k==0:
    if l[0]==1:
        print(-1)
    else:
        print(1)
else:
    if k<n and l[k-1]==l[k]:
        print(-1)
    else:
        print(l[k-1])