n=int(input())
a=list(map(int,input().split()))
m=-1
s=-1
for i in range(n):
  if(a[i]>m+1):
    s=i+1
    break
  else:
    m=max(m,a[i])
print(s)