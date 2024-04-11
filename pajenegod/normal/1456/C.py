f=lambda:sorted(map(int,input().split()))
k,n=f()
A=f()
s=c=0
while A and~c<0:s+=c;c+=A.pop()
for i,a in enumerate(A+[c]):s+=i//-~k*a
print(s)