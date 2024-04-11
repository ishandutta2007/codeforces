n,k = map(int,raw_input().split())
lis = []
flag = 0
for i in range(n+1):
	x = raw_input()
	if x == '?':
		flag += 1
	lis.append(x)
if k == 0:
	if lis[0] == '0' or lis[0] == '?' and (n + 1 - flag) % 2 == 1:
		print 'Yes'
	else:
		print 'No'
elif flag:
	if n % 2 == 1:
		print 'Yes'
	else:
		print 'No'
else:
	ans1 = ans2 = ans3 = 0
	cur1 = cur2 = cur3 = 1
	p1 = 1000000007
	p2 = 99251
	p3 = 81559
	for i in lis:
		ans1 += cur1 * int(i)
		ans2 += cur2 * int(i)
		ans3 += cur3 * int(i)
		ans1 %= p1
		ans2 %= p2
		ans3 %= p3
		cur1 *= k
		cur2 *= k
		cur3 *= k
		cur1 %= p1
		cur2 %= p2
		cur3 %= p3
	if not ans1 and not ans2 and not ans3:
		print 'Yes'
	else:
		print 'No'