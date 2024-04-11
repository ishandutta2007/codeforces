a, b = map(int, input().split())
if b - a == 0:
  print(a * 10 + 1, b * 10 + 2)
elif b - a == 1:
  print(a, b)
elif a == 9 and b == 1:
  print(9, 10)
else:
  print(-1)