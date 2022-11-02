a1 = int(input())
a2 = int(input())
k1 = int(input())
k2 = int(input())
n = int(input())
ans1 = n
ans2 = 0
for i in range(a1 + 1):
  for j in range(a2 + 1):
    if (n >= i * k1 + j * k2 and n <= i * k1 + (k1 - 1) * (a1 - i) + j * k2 + (k2 - 1) * (a2 - j)):
      ans1 = min(ans1, i + j)
      ans2 = max(ans2, i + j)
print(ans1, ans2)