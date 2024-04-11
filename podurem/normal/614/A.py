l, r, k = map(int, input().split())
kol = 0
x = 1
while (x <= r) :
   if (x >= l and x <= r) :
      print(x, end = ' ')
      kol += 1
   x = x * k
if (kol == 0) :
   print(-1)