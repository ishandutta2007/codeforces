for _ in range(int(input())):
    n=int(input())
    f=input()
    k=1
    an=f
    for i in range(1,n+1):
        if i==n:
            s=f[::-1]
        elif (n-i+1)%2==0:
            s=f[i-1:]+f[:i-1]
        else:
            s = f[i - 1:] + f[:i - 1][::-1]
        if s<an:
            an=s
            k=i
    print(an)
    print(k)