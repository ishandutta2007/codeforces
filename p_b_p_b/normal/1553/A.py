def work(n):
	res=n//10
	if n%10==9:
		res=res+1
	return res
T=int(input())
for i in range(0,T):
	n=int(input())
	print(work(n))