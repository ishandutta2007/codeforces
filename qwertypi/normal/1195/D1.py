n = int(input())

A = input().split()

_len = len(A[0])
prec = [0 for i in range(_len)]
for i in range(_len):
	for j in A:
		prec[i] += int(j[i])

ans = 0
for i in range(_len):
	ans += prec[i] * 11 * n * 10 ** (2 * (_len - 1 - i))
	
print(ans % 998244353)