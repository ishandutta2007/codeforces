n, t = map(int, input().split())

s = input()

for _ in range(t):
	cpy = list(s)
	for i in range(len(s) - 1):
		if s[i] == 'B' and s[i + 1] == 'G':
			cpy[i] = 'G'
			cpy[i + 1] = 'B'
	s = "".join(cpy)
print(s)