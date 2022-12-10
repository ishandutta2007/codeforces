n = int(raw_input())
ans = 10000
def calc(x):
	if x % 3 == 0:
		return calc(x / 3)
	return x / 3 + 1

print(calc(n))