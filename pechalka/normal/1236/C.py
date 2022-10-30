n = int(input())
first = 0
last = n - 1
for i in range(n // 2):
  for j in range(n):
    if j % 2 == 1:
      print(j * n + first + 1, end = ' ')
    else:
      print(j * n + last + 1, end = ' ')
  print()
  for j in range(n):
    if j % 2 == 1:
      print(j * n + last + 1, end = ' ')
    else:
      print(j * n + first + 1, end = ' ')
  print()
  first += 1
  last -= 1
if n % 2 == 1:
  for j in range(n):
    print(j * n + n // 2 + 1, end = ' ')