test = int(input())
#
for i in range(test):
    n,k=map(int,input().split())
    c=((n-1)//2)
    if(c<k):
        print(-1)
        continue
    p=[i+1 for i in range(n)]
    c=0
    for i in range(1,n,2):
        if(c==k):
            break
        p[i],p[i+1]=p[i+1],p[i]
        c+=1;
    print(*p)