for _ in range(int(input())):
 n = int(input())
 a = list(map(int, input().split()))
 zc = sum(1 for x in a if x == 0)
 a = [x for x in a if x != 0]
 if len(a) > 4:
  print('NO')
  continue
 if zc:
  a += [0]
 n = len(a)
 def f(a):
  for i in range(n):
   for j in range(i):
    for k in range(j):
     if a[i]+a[j]+a[k] not in a:
      print('NO')
      return
  print('YES')
 f(a)