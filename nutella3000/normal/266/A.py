n = int(input())
s = input()
cnt = 0
for i in range(len(s) - 1):
    cnt += s[i] == s[i+1]
print(cnt)