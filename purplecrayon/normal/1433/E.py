import math

def choose(n, k):
	return math.factorial(n)//math.factorial(k)//math.factorial(n-k)
	
def f(n):
	x = choose(n, n//2)
	x *= math.factorial(n//2-1)**2
	x = x//2
	return x

n = int(input())
print(f(n))