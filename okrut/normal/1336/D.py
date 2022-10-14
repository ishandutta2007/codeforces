n = int(input())

t, s = map(int, input().split())

x = n-1

while x>2:
	print("+",x)
	x-=1

print("+ {}\n+ {}\n+ {}".format(1, 2, 1), flush = True)

deltas = []
for i in range(n):
	t2, s2 = map(int, input().split())
	deltas.append([ t2 - t, s2 - s])
	s = s2
	t = t2

#print(deltas)

ans = [0] * n

x = 0
while (x+1)*x < deltas[-1][0]*2: x+=1

ans[0] = x
ans[2] = deltas[-1][1] - deltas[-3][1] -1
ans[1] = deltas[-3][1]//(ans[2]+1)

ans[3] = (deltas[-2][1] - (ans[0]+1)*(ans[2]+1))//(ans[2]+1) -1

for x in range(4,n):
	#print(deltas[-x])
	ans[x] = (deltas[-x][1] - ans[x-4] * ans[x-3] - ans[x-3]*(ans[x-1] +1))//(ans[x-1]+1) -1


ans[-1]+=1

print("!", end = ' ')
for x in ans:
	print(x, end = ' ')
print()