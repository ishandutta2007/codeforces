n = int(input())
a = list(map(int, input().split()))
ans = 1
s = set()
for i in range(n - 1):
    if (abs(a[i + 1] - a[i]) != 1):
        s.add(abs(a[i + 1] - a[i]))
if (ans == -1 or len(s) > 1 or (0 in s)):
    print("NO")
else:
    if (len(s) > 0):
        ans = s.pop()
    for i in range(n - 1):
        a1 = min(a[i], a[i + 1])
        a2 = max(a[i], a[i + 1])
        if ((a2 - a1) == 1 and a1 % ans == 0 and ans != 1):
            ans = -1
            break
    if (ans == -1):
        print("NO")
    else:
        print("YES")
        print(10 ** 9, ans)