

l, r = map(int, input().split())
l += l % 2
if r - l >= 2:
  print(l, l + 1, l + 2)
else:
  print(-1)