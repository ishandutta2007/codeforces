x=int(input())
a=list(map(int,input().split()))
for i in range(x):
    if a[i]%4==0 or a[i]%2==0:
        print(a[i]*4+1)
    elif a[i]%4==3:
        print(a[i]+1)
    else:
        print(a[i]*2+1)