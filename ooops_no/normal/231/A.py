a=int(input())
b=0
d=0
while b<a: 
 p=0
 k=[int(i)for i in input().split()]
 for j in k:
  if j==1:
   p+=1
 if p>=2:
  d+=1
 b+=1
print(d)