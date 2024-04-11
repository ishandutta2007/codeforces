q = int(input())
 
while q > 0:
	q = q - 1
	s = raw_input().split()
	if s[0] != s[2]:
		print "%d %d" % (int(s[0]), int(s[2]))
	else:
		print "%d %d" % (int(s[0]), int(s[3]))