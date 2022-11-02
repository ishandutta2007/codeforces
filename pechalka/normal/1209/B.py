n = int(input())
s = input()
used = [0] * n
for i in range(n):
  if s[i] == '0':
    used[i] = False
  else:
    used[i] = True
a = [0] * n
b = [0] * n
for i in range(n):
  a[i], b[i] = map(int, input().split())

ans = 0
for time in range(500):
  for i in range(n):
    if time >= b[i] and (time - b[i]) % a[i] == 0:
      used[i] = not used[i]
  cnt = 0
  for i in range(n):
    if used[i]:
      cnt += 1
  ans = max(ans, cnt)
print(ans)