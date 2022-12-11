n,k = map(int,raw_input().split())
l = int(n-k)
li = int(1)
ri = int(n)
for i in range (1,n+1):
	if i<l:
		print li
		li = li + 1
	else:
		print ri
		ri = ri - 1