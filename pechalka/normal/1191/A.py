x = int(input())
if x % 4 == 2:
  print("1 B")
else:
  print((5 - x % 4) % 4, 'A')