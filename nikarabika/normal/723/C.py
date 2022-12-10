inp = [int(x) for x in raw_input().split()]
n = inp[0]
m = inp[1]
a = [int(x) - 1 for x in raw_input().split()]
cnt = [0 for i in range(m + 1)]
mark = [False for i in range(m + 1)]
for val in a:
	cnt[min(val, m)] += 1
ans = 0

def need(x):
	if x >= m:
		return 0
	return n/m

for i in range(n):
	if cnt[min(m, a[i])] > need(a[i]):
		for j in range(m):
			if cnt[j] < need(j):
				cnt[min(m, a[i])] -= 1
				cnt[j] += 1
				a[i] = j
				ans += 1
				break
print n / m, ans
for x in a:
	print x+1,