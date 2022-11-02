n = int(input())
if n % 2 == 1:
  print("YES")
  i = 1
  while i < 2 * n - 1:
    print(i, end = ' ')
    print(i + 3, end = ' ')
    i += 4
  print(i, end = ' ')
  i = 2
  while i < 2 * n:
    print(i, end = ' ')
    print(i + 1, end = ' ')
    i += 4
  print(i, end = ' ')
else:
  print("NO")