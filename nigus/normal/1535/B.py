import math
T=int(input())
for _ in range(T):
    n=int(input())
    a=input().split()
    a0=[]
    a1=[]
    for x in a:
        x=int(x)
        if x%2 == 0:
            a0.append(x)
        else:
            a1.append(x)
    a=a0+a1
    ans=0
    for i in range(n):
        for j in range(i+1,n):
            ans+=(math.gcd(a[i],2*a[j])>1)
    print(ans)