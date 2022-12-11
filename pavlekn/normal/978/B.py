n = int(input())
s = input()
ans = ''
for i in range(n):
    if not(len(ans) > 1 and 'x' == s[i] == ans[-1] == ans[-2]):
        ans += s[i]
print(n - len(ans))