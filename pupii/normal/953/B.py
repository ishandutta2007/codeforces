n=input()
A=[int(i) for i in raw_input().split()]
A.sort()
def gcd(a,b):
	if b:return gcd(b,a%b)
	else:return a
g=0
for i in range(1,n):g=gcd(g,A[i]-A[i-1])
print (A[-1]-A[0])/g-n+1