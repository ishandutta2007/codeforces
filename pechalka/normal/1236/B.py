MOD = 10 ** 9 + 7
def power(a, n):
  if n == 0:
    return 1
  if n % 2 == 0:
    return power(a, n // 2) ** 2 % MOD
  return power(a, n - 1) * a


n, m = map(int, input().split())
print(power(power(2, m) + MOD - 1, n) % MOD)