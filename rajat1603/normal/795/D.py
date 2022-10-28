n , l , r = map(int , raw_input().split())
a = map(int , raw_input().split())
b = map(int , raw_input().split())
l -= 1
r -= 1
a1 = []
a2 = []
a3 = []
for i in range(0 , n):
	if i < l:
		a1.append(a[i])
	elif i <= r:
		a2.append(a[i])
	else:
		a3.append(a[i])

b1 = []
b2 = []
b3 = []
for i in range(0 , n):
	if i < l:
		b1.append(b[i])
	elif i <= r:
		b2.append(b[i])
	else:
		b3.append(b[i])

a2.sort()
b2.sort()

if a1 == b1 and a2 == b2 and a3 == b3:
	print "TRUTH"
else:
	print "LIE"