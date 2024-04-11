for _ in range(int(input())):
    n,m=map(int,input().split())
    a=[int(i) for i in input().split()]
    s=sum(a)
    if s>m:
        print(m)
    else:
        print(s)