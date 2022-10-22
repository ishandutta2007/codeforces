for _ in range(int(input())):
    n,m=map(int,input().split())
    a=input()
    b=[int(i) for i in input().split()]
    b.append(n)
    c=[0]*26
    #ord a == 97
    f=[0]*(n+1)
    for i in range(m+1):
        f[b[i]-1]+=1
    x=f[n]
    for i in range(n-1,-1,-1):
        x+=f[i]
        c[ord(a[i])-97]+=x

    print(*c)