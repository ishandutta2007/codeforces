for _ in range((int(input()))):
    n,d=map(int,input().split())
    a=[int(i) for i in input().split()]
    x=a[0]
    for i in range(1,n):
        if d==0:
            break
        x+=a[i]
        d-=a[i]*i
        if d<0:
            d=-d
            x-=((d+i-1)//i)
            break
    print(x)