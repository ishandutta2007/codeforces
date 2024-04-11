n = int(input())
c = [list(map(int, input().split())) for i in range(n)]
s = set()

from itertools import *
for i in permutations(c):
	for j in product(range(6), repeat=n):
		v = []
		for k in range(n):
			v.append(i[k][j[k]] * 10 ** k)
		for k in accumulate(v):
			s.add(k)
		
t = set(range(1, 10**n))
ans = min(t - s) - 1
print(ans)