n, k = map(int, input().split())
print ("No" if any(n % i != i - 1 for i in range(1, k + 1)) else "Yes")