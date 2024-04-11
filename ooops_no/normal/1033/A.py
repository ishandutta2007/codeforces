x=int(input())
a=[int(i)for i in input().split()]
b=[int(i)for i in input().split()]
c=[int(i)for i in input().split()]
if b[0]<a[0] and b[1]<a[1]:
    if c[0]<a[0] and c[1]<a[1]:
        print("YES")
    else:
        print("NO")
elif b[0]<a[0] and b[1]>a[1]:
    if c[0]<a[0] and c[1]>a[1]:
        print("YES")
    else:
        print("NO")
elif b[0]>a[0] and b[1]>a[1]:
    if c[0]>a[0] and c[1]>a[1]:
        print("YES")
    else:
        print("NO")
elif b[0]>a[0] and b[1]<a[1]:
    if c[0]>a[0] and c[1]<a[1]:
        print("YES")
    else:
        print("NO")