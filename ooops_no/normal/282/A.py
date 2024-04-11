x=int(input())
b=0
k=0
while b<x:
 l=input()
 if "+" in l:
  k+=1
 else:
  k-=1
 b+=1
print(k)