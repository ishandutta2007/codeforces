s = input().split("WUB")
ans = ""
cnt = 0
for i in s:
	if len(i) == 0:
		continue
	cnt += 1
	if cnt > 1:
		ans += " "
	ans += i
print(ans)