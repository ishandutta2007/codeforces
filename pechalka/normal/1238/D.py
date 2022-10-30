n = int(input())
s = input()
blocks = 1
first = 1
last = 1
while first < n and s[first] == s[first - 1]:
  first += 1
while last < n and s[-last - 1] == s[-last]:
  last += 1
for i in range(1, n):
  if s[i] != s[i - 1]:
    blocks += 1
print(n * (n - 1) // 2 - (2 * n + 1 - first - last - blocks))