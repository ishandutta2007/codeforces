
n = int(input())
s = []
for i in range(n):
  s.append(input())
for i in range(n):
  for j in range(n):
    os = 0
    for dx, dy in [(-1, 0), (0, -1), (1, 0), (0, 1)]:
      x = i + dx
      y = j + dy
      if x < 0 or y < 0 or x >= n or y >= n:
        continue
      if s[x][y] == 'o':
        os += 1
    if os % 2 != 0:
      print('NO')
      exit()
print('YES')