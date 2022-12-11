n = int(input())
s = input()
ans = []
count = []
for i in range(n - 1):
    if (s[i:i + 2] in ans):
        count[ans.index(s[i:i + 2])] += 1
    else:
        ans.append(s[i:i + 2])
        count.append(1)
x = max(count)
print(ans[count.index(x)])