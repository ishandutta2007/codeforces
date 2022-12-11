n = int(input())
s = input()
for i in range(n // 2, -1, -1):
    if (s[:i] == s[i:2 * i]):
        break
print(min(n, n + 1 - i))