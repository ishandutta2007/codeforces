s = input()
n = len(s)
ans = 0
for i in range(n):
    for j in range(i + 1, n + 1):
        s2 = s[i:j][::-1]
        if (s[i:j] != s2):
            ans = max(ans, j - i)
print(ans)