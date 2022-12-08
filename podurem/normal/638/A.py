n, m = map(int, input().split())
if (m % 2 == 0) :
   m = n - m + 1
print(m // 2 + 1)