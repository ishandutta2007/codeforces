table = {}
cur = 1


def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a%b)


def read():
	global cur
	global table
	s = input().split('/')
	nom = eval(s[0])
	den = int(s[1])
	g = gcd(nom, den)
	nom //= g
	den //= g
	h_code = nom * 1000 + den
	if h_code in table:
		table[h_code].append(cur)
	else:
		table[h_code] = [cur]
	cur += 1


m = int(input())
for i in range(m):
	read()
ans = [0] * 213456

for key, val in table.items():
	for idx in val:
		ans[idx] = len(val)

for i in range(1, m+1):
	print(ans[i], end = " ")