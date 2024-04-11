n=input()
x=map(int,raw_input().split())
q=0
for i in x:
    q^=i
lis=[0]
for i in range(1,n+1):
    lis.append(lis[-1]^i)
for i in range(1,n+1):
    if (n/i)%2==0:
        q^=lis[n%i]
    else:
        q^=lis[n%i]^lis[i-1]
print q