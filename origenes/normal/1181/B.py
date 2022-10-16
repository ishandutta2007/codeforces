l = int(input())
s = input()
lis = [i for i in range(1, l) if s[i] != '0']
lis.sort(key = lambda i : abs(i - l / 2))
ans = 10 ** int(1e5)
for i in lis[:6]:
    ans = min(ans, int(s[i:]) + int(s[:i]))
print(ans)