n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
b1 = []
a1 = []
for i in range(n):
	b1.append(b[i])
	a1.append(a[i])
b1.sort()
a1.sort()
a1.reverse()
d = dict()
for i in range(n):
	if b1[i] in d: d[b1[i]].append(a1[i])
	else: d[b1[i]] = [a1[i]]
for i in range(n):
	a[i] = d[b[i]][len(d[b[i]]) - 1]
	d[b[i]].pop()
print(*a)