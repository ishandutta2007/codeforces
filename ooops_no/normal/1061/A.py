n,sum=map(int,input().split())
if sum%n==0:
    print(sum//n)
else:
    print(sum//n+1)