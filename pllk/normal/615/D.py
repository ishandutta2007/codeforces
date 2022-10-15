N = 202020
M = 1000000007
n = int(raw_input())
x = [int(s) for s in raw_input().split(" ")]
t = 1
k = 1
c = [0]*202020
for u in x:
	c[u] += 1
for i in range(1,N):
	if c[i] == 0:
		continue
	z = 1
	t2 = 1
	k2 = 0
	for j in range(c[i]):
		z *= i
		z %= M
		t2 *= t*pow(z,k,M)
		k2 += k
		t2 %= M
	t *= t2
	k = k+k2
	k %= (M-1)
	t %= M
print t