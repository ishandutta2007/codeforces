n = int(input())
a = list(map(int,input().split()))
i = 0
j = n - 1
now = 1
ans1 = 0
ans2 = 0
while (i <= j):
	cur = 0
	if (a[i] > a[j]):
		cur = a[i]
		i += 1
	else:
		cur = a[j]
		j -= 1
	if (now == 1):
		ans1 += cur
	else:
		ans2 += cur
	now = 1 - now
print(ans1, ans2)