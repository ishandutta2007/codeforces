
def check(k):
	i = 2
	ret = 1
	while i * i <= k:
		if k % i == 0:
			ret = 0
		i += 1
	return ret

n = int(input())

if n == 2:
	print -1;
	exit();

el = []

for i in range(0, n):
	el.append(1)
for i in range(0, n):
	el[i] = 1
p = 2

for i in range(0, n):
	while check(p) == 0:
		p += 1
	for j in range(0, n):
		if i != j:
			el[j] *= p
	p += 1

	
for i in el:
	print i