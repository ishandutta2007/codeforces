import math
import sys

n=int(input())
x=[]
a=[]
p=[]
m=[]
for i in range(0,n):
    inp=list(map(int,input().split()))
    x.append(inp[0])
    a.append(inp[1])
    if x[i] < 0:
        m.append(-x[i]*1000000+a[i])
        
    else:
        p.append(x[i]*1000000+a[i])
m.sort()
p.sort()

i=0
ans=0
while i < len(m) and i < len(p):
    
    ans+=m[i]%1000000
    ans+=p[i]%1000000
    i+=1

if i < len(m):
    ans+=m[i]%1000000

if i < len(p):
    ans+=p[i]%1000000
print(ans)