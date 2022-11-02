x=int(input())
for _ in range(x):
    a=[int(i)for i in input().split()]
    l=a[0]//a[1]
    b=a[3]//a[1]-(a[2]-1)//a[1]
    print(l-b)