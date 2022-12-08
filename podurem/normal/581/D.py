x1, y1, x2, y2, x3, y3 = map(int, input().split())
x1, y1 = max(x1, y1), min(x1, y1)
x2, y2 = max(x2, y2), min(x2, y2)
x3, y3 = max(x3, y3), min(x3, y3)
x1c, y1c, x2c, y2c, x3c, y3c = x1, y1, x2, y2, x3, y3
if x2 == max(x1, x2, x3) :
	x1, y1, x2, y2 = x2, y2, x1, y1
elif x3 == max(x1, x2, x3) :
	x1, y1, x3, y3 = x3, y3, x1, y1
if x1 == x1c and y1 == y1c and x2 == x2c and y2 == y2c :
	s1 = 'A'
	s2 = 'B'
	s3 = 'C'
elif x1 == x1c and y1 == y1c and x2 == x3c and y2 == y3c :
	s1 = 'A'
	s2 = 'C'
	s3 = 'B'
elif x1 == x2c and y1 == y2c and x2 == x1c and y2 == y1c :
	s1 = 'B'
	s2 = 'A'
	s3 = 'C'
elif x1 == x2c and y1 == y2c and x2 == x3c and y2 == y3c :
	s1 = 'B'
	s2 = 'C'
	s3 = 'A'
elif x1 == x3c and y1 == y3c and x2 == x1c and y2 == y1c :
	s1 = 'C'
	s2 = 'A'
	s3 = 'B'
elif x1 == x3c and y1 == y3c and x2 == x2c and y2 == y2c :
	s1 = 'C'
	s2 = 'B'
	s3 = 'A'
if x1 == x2 == x3 and y1 + y2 + y3 == x1 :
	print(x1)
	for i in range(x1) :
		for j in range(x1) :
			if i < y1 :
				print(s1, end = '')
			elif y1 <= i < y1 + y2 :
				print(s2, end = '')
			else :
				print(s3, end = '')
		print()
elif x1 == y2 + x3 and x2 + y1 == y3 + y1 == x1 :
	print(x1)
	for i in range(x1) :
		for j in range(x1) :
			if i < y1 :
				print(s1, end = '')
			else :
				if j < y2 :
					print(s2, end = '')
				else :
					print(s3, end = '')					
		print()
elif x1 == x2 + y3 and y2 + y1 == x3 + y1 == x1 :
	print(x1)
	for i in range(x1) :
		for j in range(x1) :
			if i < y1 :
				print(s1, end = '')
			else :
				if j < x2 :
					print(s2, end = '')
				else :
					print(s3, end = '')					
		print()
elif x1 == x2 + x3 and y2 + y1 == y3 + y1 == x1 :
	print(x1)
	for i in range(x1) :
		for j in range(x1) :
			if i < y1 :
				print(s1, end = '')
			else :
				if j < x2 :
					print(s2, end = '')
				else :
					print(s3, end = '')					
		print()
elif x1 == y2 + y3 and x2 + y1 == x3 + y1 == x1 :
	print(x1)
	for i in range(x1) :
		for j in range(x1) :
			if i < y1 :
				print(s1, end = '')
			else :
				if j < y2 :
					print(s2, end = '')
				else :
					print(s3, end = '')					
		print()
else :
	print(-1)