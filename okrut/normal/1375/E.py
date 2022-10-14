n = int(input())

A = list(map(int, input().split()))

res = []
for i in range(n):
	curr = []
	for j in range(i,n):
		if A[i] > A[j]:
			curr.append([A[j], j])
		
	curr.sort()
	curr.reverse()
		
	for inw in curr:
		res.append([i, inw[1]])

print(len(res))
for inw in res:
	print(inw[0]+1, inw[1]+1)