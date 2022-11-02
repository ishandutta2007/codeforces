x=int(input())
l=list(map(int,input().split()))
l1=[]
for i in range(x):
    if l1!=[] and l[i]%2==l1[-1]:
        del l1[-1]
    else:
        l1+=[l[i]%2]
if len(l1)<=1:
    print("YES")
else:
    print("NO")