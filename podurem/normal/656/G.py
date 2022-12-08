f,e,t=map(int,input().split())
a=[0]*f
for i in range(f):
   a[i]=input()
n=0
for i in range(e):
   k=0
   for j in range(f):
      k+=(a[j][i]=='Y')
   n+=(k>=t)
print(n)#kitten