x = list(map(int, input().split()))
n = x[0]
k = x[1]
ans = 0

for i in range(n):
	a = input()
	used = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	for c in a:
		used[int(c)] = 1
	cnt = 0
	for c in range(0, k + 1):
		cnt += used[c]
	if (cnt == k + 1):
		ans += 1
print(ans)