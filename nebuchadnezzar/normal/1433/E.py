import math

def cnk(n, k):
	return math.factorial(n) // math.factorial(k) // math.factorial(n - k)

n = int(input())

print(cnk(n, n // 2) // 2 * math.factorial(n // 2 - 1) ** 2)