n = int(input())
if n % 10 < 5:
    n = n // 10 * 10
else:
    n = (n // 10 + 1) * 10
print(n)