q=int(input())
for i in range(q):
    l,r=map(int,input().split())
    if l==r and l%2==1:
        print(-l)
    elif l==r:
        print(l)
    elif l%2==0 and r%2==1:
        print(-((r-l)//2+1))
    elif l%2==0 and r%2==0:
        print(r-(r-l)//2)
    elif l%2==1 and r%2==1:
        print(-(r-(r-l)//2))
    else:
        print((r-l)//2+1)