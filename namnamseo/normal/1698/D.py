for _ in range(int(input())):
 n = int(input())
 l, r = 1, n
 while l < r:
  m = (l+r) // 2
  print('?', l, m, flush=True)
  ret = list(map(int, input().split()))
  c = sum(1 for x in ret if l<=x and x<=m)
  if c%2 == 1:
   r = m
  else:
   l = m+1
 print('!', l)