s = input()
s = '00' + s
u = 0
for i in range(len(s)):
    for j in range(i + 1, len(s)):
        for k in range(j + 1, len(s)):
            if (int(s[i] + s[j] + s[k]) % 8 == 0 and u == 0):
                print("YES")
                u = 1
                ans = s[i] + s[j] + s[k]
                if (s[i] == '0'):
                    ans = ans[1:]
                    if (s[j] == '0'):
                        ans = ans[1:]
                print(ans)
if (u == 0):
    print('NO')