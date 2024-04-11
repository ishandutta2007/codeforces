s = input()
ans = 0
a = ['1', '3', '5', '7', '9', 'a', 'o', 'u', 'i', 'e']
for i in range(len(s)):
    if (s[i] in a):
        ans += 1
print(ans)