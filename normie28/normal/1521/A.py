t=int(input())
for t1 in range(t):
	a, b = input().split()
	a=int(a)
	b=int(b)
	if (b==1):
		print("NO")
	else:
		print("YES")
		print(a,a*b,a*b+a)