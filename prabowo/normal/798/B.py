s = [input() for i in range(int(input()))]

ans = 10**9
for i in range(len(s[0])):
  tmp = i
  cnt = 0
  for j in range(1, len(s)):
    for k in range(len(s[j])):
      if (s[0][i:] + s[0][:i] == s[j][k:] + s[j][:k]):
        tmp += k
        cnt += 1
        break
        
  if (cnt == len(s) - 1): ans = min(ans, tmp)
  
print(ans if ans < 10**9 else -1)