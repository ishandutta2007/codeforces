n = input()
lis = map(int, raw_input().split())
s = sum(lis)
if s != 0:
	print 'YES'
	print 1
	print 1, n
else:
	ans = -1
	for i in range(n - 1):
		if sum(lis[:i + 1]) != 0:
			ans = i + 1
			break
	if ans == -1:
		print 'NO'
	else:
		print 'YES'
		print 2
		print 1, ans
		print ans + 1, n