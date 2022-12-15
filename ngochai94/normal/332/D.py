n, k = map(int, raw_input().split())
lis = [[-1 for i in range(n)] for j in range(n)]
for i in range(n - 1):
	tmp = map(int, raw_input().split())
	for j in range(i + 1, n):
		lis[i][j] = lis[j][i] = tmp[j - i - 1]
fac = [0 for i in range(n + 1)]
fac[k] = 1;
for i in range(k + 1, n + 1):
	fac[i] = fac[i - 1] * i / (i - k)
s = 0
cnt = 0
for i in range(n):
	curs = 0
	curcnt = 0
	for j in range(n):
		if lis[i][j] != -1:
			curs += lis[i][j]
			curcnt += 1
	cnt += fac[curcnt]
	s += curs * fac[curcnt] * 1.0 / curcnt
	# print curs, curcnt
# print s, cnt
print int(s / cnt * k)