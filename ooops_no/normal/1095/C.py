a,b=map(int,input().split())
l=[int(1)for i in range(b)]
sum=b
for i in range(b):
    while sum+l[i]<=a:
        sum+=l[i]
        l[i]*=2
if sum==a:
    print("YES")
    for i in l:
        print(i,end=" ")
else:
    print("NO")