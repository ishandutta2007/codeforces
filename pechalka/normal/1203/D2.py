s = input()
t = input()
n = len(s)
m = len(t)
dp1 = [0] * (n + 1)
for i in range(n):
  dp1[i + 1] = dp1[i]
  if (dp1[i] < m and s[i] == t[dp1[i]]):
    dp1[i + 1] += 1
dp2 = [0] * (n + 1)
for i in range(n - 1, -1, -1):
  dp2[i] = dp2[i + 1]
  if (dp2[i + 1] < m and s[i] == t[-1 - dp2[i + 1]]):
    dp2[i] += 1

def check(ln):
  for i in range(n - ln + 1):
    if ((dp1[i] + dp2[i + ln]) >= m):
      return True
  return False

l, r = 0, n
while (r - l > 1):
  mid = (l + r) // 2
  if (check(mid)):
    l = mid
  else:
    r = mid
print(l)