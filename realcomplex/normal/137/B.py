n = int(raw_input())
el = set(raw_input().split())
k = 0
cnt = 0
for x in el:
	k = int(x)
	if k<=n:
		cnt = cnt + 1
print n-cnt