n = int(input())
arr = [int(i) for i in input().split()]

limak = arr.pop(0)
ans = 0

arr.sort()
while (arr[n-2] >= limak) :
	arr[n-2] -= 1
	limak += 1
	ans += 1
	arr.sort()
	
print(ans)