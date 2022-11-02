x=int(input())
for _ in range(x):
    a=[int(i)for i in input().split()]
    n=a[0]-a[1]
    if n!=1:
        print("NO")
    else:
        n=a[0]+a[1]
        l=True
        for i in range(2,int(n**0.5)+1):
            if n%i==0:
                l=False
                break
        if l:
            print("YES")
        else:
            print("NO")