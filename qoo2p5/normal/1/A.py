n, m, a = map(int, input().split())

print((n // a + bool(n % a)) * (m // a + bool(m % a)))