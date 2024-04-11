I=input().split()
n=int(I[0])
k=int(I[1])
if k==1:
 print(n)
else:
 t=1
 while t<=n: t*=2
 print(t-1)