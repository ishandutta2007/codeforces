s = input()
ans = (len(s) - 1) // 2
add = False
for i in range(1, len(s)):
  if s[i] == '1':
    add = True
if add or len(s) % 2 == 0:
  ans += 1
print(ans)