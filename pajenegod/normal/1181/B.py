f=input
n=f()
v=A=str(f())
for k,i in(-1,n/2),(1,(n+1)/2):
 while i<n and'1'>A[i]:i+=k
 if 0<i<n:v=min(v,int(A[:i])+int(A[i:]))
print v