def all_different(year):
	s = "".join(sorted(str(year)))

	for i in range(len(s) - 1):
		if s[i] == s[i + 1]:
			return False
	return True

year = int(input())

year += 1
while not all_different(year):
	year += 1
print(year)