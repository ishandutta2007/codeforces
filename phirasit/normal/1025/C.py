s = input().strip()
n = len(s)
s = s + s

cnt = ans = 1
for i in range(1, len(s)):
    cnt = (cnt+1) if s[i] != s[i-1] else 1
    ans = max(ans, cnt)
if ans > n: ans = n
print (ans)