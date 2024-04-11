q = int(input())
while q > 0:
	s = raw_input().split()
	n = int(s[0])
	a = int(s[1])
	b = int(s[2])
	b = min(b, 2*a)
	print n % 2 * a + n / 2 * b
	q = q - 1