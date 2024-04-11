n = int(raw_input())
s = map(int,raw_input().split())
l = 0
for i in s:
	if(i-l>15):
		print l+15
		quit()
	l = i
print min(l+15,90)