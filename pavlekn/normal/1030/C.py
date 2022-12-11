n = int(input())
s = input()
a = []
for i in range(n):
    a.append(int(s[i]))
s = sum(a)
ans = "NO"
for i in range(2, 1001):
    if (s % i != 0):
        continue
    su = s // i
    pos = 0
    ans = "YES"
    for ii in range(i):
        cur = 0
        while (pos < n and cur + a[pos] <= su):
            cur += a[pos]
            pos += 1
        if (cur != su):
            ans = "NO"
    if (ans == "YES"):
        break
print(ans)