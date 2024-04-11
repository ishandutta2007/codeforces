a,b=map(int,input().split())
x=list(map(int,input().split()))
x.sort()
counter=0
counter+=abs(b-x[a//2])
for i in range(a//2):
    if x[i]>=b:
        counter+=abs(b-x[i])
for i in range(a//2+1,a):
    if x[i]<=b:
        counter+=abs(b-x[i])
print(counter)