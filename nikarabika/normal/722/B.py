n = int(raw_input())
str = raw_input()
p = [int(x) for x in str.split()]
may = False
for i in range(n):
	str = raw_input()
	cnt = 0
	for c in str:
		if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y':
			cnt += 1
	if cnt != p[i]:
		may = True
if may:
	print("NO")
else:
	print("YES")