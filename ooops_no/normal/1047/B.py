a=int(input())
l=[0]
for i in range(a):
    x=[int(i)for i in input().split()]
    if l[0]<sum(x):
        l[0]=sum(x)
print(l[0])