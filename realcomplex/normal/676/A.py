
n = int(input())

l = 0
r = 0
sk = map(int,raw_input().split())
p = 1
for x in sk:
	if x == n:
		r = p
	if x == 1:
		l = p
	p = p + 1
print max(max(l-1,r-1),max(abs(r-l),abs(n-min(r,l))));