for _ in range(int(input())):
    n,m=map(int,input().split())
    a=[int(i) for i in input().split()]
    b=[int(i) for i in input().split()]
    ch = True
    for i in range (n-1):
        f=max(a[:n-i])
        g=a.index(f)
        for j in range(g, n-i-1):
            if ch:
                a[j],a[j+1]=a[j+1],a[j]
                if j+1 not in b and a[j]!=a[j+1]:
                    ch=False
                    break
    if ch:
        print("YES")
    else:
        print("NO")