n = int(input())
s = input()
prev = - 1
ans = ""
t = -1
flag = 1
for i in range(n):
    cur = ord(s[i]) - ord('a')
    if cur >= prev:
        ans += "1"
        prev = cur
    else:
        if cur < t:
            flag = 0
            break
        t = cur
        ans += "0"
if flag:
    print("YES")
    print(ans)
else:
    print("NO")