for _ in range(int(input())):
    n=int(input())
    x=0
    a=[int(i)for i in input().split()]
    a=sorted(a)
    x=abs(a[n-1]-a[n])
    print(x)