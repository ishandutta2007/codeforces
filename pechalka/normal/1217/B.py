t = int(input())
for query in range(t):
  n, x = map(int, input().split())
  maxd = 0
  maxdelta = -1000000000
  for i in range(n):
    d, h = map(int, input().split())
    maxd = max(maxd, d)
    maxdelta = max(maxdelta, d - h)
  if maxdelta <= 0:
    if maxd >= x:
      print(1)
    else:
      print(-1)
  else:
    print((max(0, x - maxd) + maxdelta - 1) // maxdelta + 1)