t = int(input())
for i in range(t) :
   n = int(input())
   ans = n * (n + 1) // 2;
   x = 1;
   while (x * 2 <= n) :
      x *= 2;
   ans -= 2 * (x * 2 - 1);
   print(ans)