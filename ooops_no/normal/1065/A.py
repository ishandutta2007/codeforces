x=int(input())
for _ in range(x):
    a=[int(i)for i in input().split()]
    s=a[0]
    f=a[1]
    h=a[2]
    j=a[3]
    l=0
    l+=s//j+s//j//f*h
    print(l)