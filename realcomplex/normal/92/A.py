n,m = map(int,input().split())
s = int(n*(n+1)/2)
m = m%s

for i in range(1,n):
	if(m<i):
		break
	m= m-i
print(m)