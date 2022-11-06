m =	{}
n = int(raw_input())
a = map(int, raw_input().split())
su = 0
ans = 0
for i in range(n):
	cn = 0
	if a[i] in m:
		cn += m[a[i]]
		ans += m[a[i]] * a[i]
	if a[i] + 1 in m:
		cn += m[a[i] + 1]
		ans += m[a[i] + 1] * (a[i] + 1)
	if a[i] - 1 in m:
		cn += m[a[i] - 1]
		ans += m[a[i] - 1] * (a[i] - 1)
	ans += (a[i] * (i - cn) - su)
	su += a[i]
	if a[i] in m:
		m[a[i]] += 1
	else:
		m[a[i]] = 1
print(ans)