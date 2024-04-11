n = int(input())
a = list(map(int, input().split()))
ans2 = sorted(a)
ans = []
for i in range(n):
    for i in range(10000):
        for j in range(1, len(a)):
            if (abs(a[j] - a[j - 1]) > 1):
                if (a[j] > a[j - 1]):
                    a[j] -= 1
                    a[j - 1] += 1
                else:
                    a[j] += 1
                    a[j - 1] -= 1
    max_x = a[0]
    i_x = 0
    for j in range(len(a)):
        if (a[j] > max_x):
            max_x = a[j]
            i_x = j
    ans.append(max_x)
    a.pop(i_x)
ans.reverse()
if (ans == ans2):
    print("YES")
else:
    print("NO")