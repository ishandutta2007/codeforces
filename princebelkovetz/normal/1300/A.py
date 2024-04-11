for _ in range(int(input())):
    n=int(input())
    x=0
    a=[int(i)for i in input().split()]
    for i in range(n):
        if a[i]==0:
            a[i]+=1
            x+=1
    if sum(a)==0:
        x+=1
    print(x)