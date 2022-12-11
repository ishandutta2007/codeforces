n,m = map(int,raw_input().split())
g = map(int,raw_input().split())
bus = 0
hold = 0
for i in g:
	if hold>=int(i):
		hold-=int(i)
	else:
		bus = bus + 1
		hold = m-int(i)
print bus