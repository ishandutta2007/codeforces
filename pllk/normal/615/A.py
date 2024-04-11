n, m = [int(s) for s in raw_input().split(" ")]
x = [0]*(m+1)
for i in range(n):
	u = [int(s) for s in raw_input().split(" ")]
	for a in u[1:]:
		x[a] = 1
for i in range(1,m+1):
	if x[i] == 0:
		print "NO"
		exit(0)
print "YES"