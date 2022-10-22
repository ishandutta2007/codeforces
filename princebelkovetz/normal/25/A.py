n=int(input())
a=[int(i) for i in input().split()]
for i in range(n):
    if a[i]%2==0:
        a[i]=-1
    else:
        a[i]=1
if sum(a)<0:
    for i in range(n):
        if a[i]==1:
            print(i+1)
            break
else:
    for i in range(n):
        if a[i] == -1:
            print(i + 1)
            break