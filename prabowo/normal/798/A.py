s = input()

cnt = 0
for i in range(len(s)):
  if (s[i] != s[len(s) - i - 1]): cnt += 1
  
print("YES" if (cnt == 2) or (cnt == 0 and len(s) % 2 == 1) else "NO")