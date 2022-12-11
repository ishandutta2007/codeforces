n,k = map(int,raw_input().split())
for i in range(0,n):
	for j in range (0,n):
		if(i==j):
			print k
		else:
			print 0