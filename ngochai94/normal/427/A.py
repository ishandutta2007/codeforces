n=input()
x=raw_input().split()
ans=0
a=0
for i in range(n):
    a+=int(x[i])
    if a<0:
        ans+=1
        a=0
print ans