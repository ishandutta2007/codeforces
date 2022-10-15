
a = []
n, k = map(int, input().split())
s = list(input())
for c in range(0, 26):
  ch = chr(c + ord('A'))
  a.append((s.count(ch), ch))
a.sort()
a.reverse()
ans = 0
for f, g in a:
  get = min(k, f)
  ans += get * get
  k -= get
print(ans)