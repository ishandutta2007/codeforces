p, y = map(int, input().split())
for i in range(y, p, -1):
	# print (min(p, int(i ** 0.5 + 1)))
	if all(i % j != 0 for j in range(2, min(p, int(i ** 0.5 + 1)) + 1)):
		print (i)
		exit()
print (-1)