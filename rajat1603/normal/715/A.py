n = input()
print 2
for i in range(2 , n + 1):
	tmp1 = ((i + 1) ** 2) * (i ** 2)
	tmp2 = i * i - i
	tmp3 = tmp1 - tmp2
	print tmp3 / i