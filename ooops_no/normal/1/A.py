n, m, a = map(int, input().split())
sum = m // a
if m % a != 0:
    sum += 1
sum1 = n // a
if n % a != 0:
    sum1 += 1
print(sum * sum1)