n, m = map(int, raw_input().split())
lis1 = map(int, raw_input().split())
lis2 = map(int, raw_input().split())
if max(lis1) < max(lis2):
	lis1, lis2 = lis2, lis1
	n, m = m, n
ans = sum(lis2)
flag = False
max1 = max(lis1)
sum2 = ans
for i in lis1:
	if not flag and i == max1:
		flag = True
		continue
	ans += min(i, sum2)
print ans