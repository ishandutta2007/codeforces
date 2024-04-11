n = int(input())
for i in range(1 , n + 1):
  if i == 1:
    print (2)
  else:
    print (i * (i + 1) * (i + 1) - i + 1)