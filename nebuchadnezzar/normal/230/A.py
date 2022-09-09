s, n = map(int, raw_input().strip().split())
mas = [0] * n

for i in xrange(n):
	x, y = map(int, raw_input().strip().split())
	mas[i] = [x, y]

mas.sort()

truly = True
for i in xrange(n):
	if(mas[i][0] < s):
		s += mas[i][1]
	else:
		print "NO"
		truly = False
		break

if(truly == True):
	print "YES"