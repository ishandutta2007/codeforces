# Not my code https://codeforces.com/contest/1367/submission/84384173
for p in range(int(input())):
	n = int(input())
	a = [int(i) for i in input().split()][:n]
	b = a.copy()
	b.sort()
	c = -1
	for e in range(len(a)):
		m=0
		g = e
		for j in range(len(a)):
				if g < len(a) and a[j] == b[g]:
					g+=1
					m+=1
		c = max(c,m)
	print(n - c)