str = raw_input()
str = raw_input() + '_'
cur = 0
mx = 0
cnt = 0
par = False
for c in str:
	if c.isalpha() and not par:
		cur += 1
	else:
		mx = max(mx, cur)
		cur = 0
		if c == '(':
			par = True
		elif c == ')':
			par = False

for i in range(len(str)):
	if(str[i] == '('):
		fnd = False
		for j in range(i, len(str)):
			if str[j] == ')' and not fnd:
				fnd = True
				for k in range(i + 1, j):
					if str[k].isalpha() and not str[k - 1].isalpha():
						cnt += 1
			if fnd:
			   break
print mx, cnt