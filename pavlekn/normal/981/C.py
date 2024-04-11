n = int(input())
flag = True
f = [0] * (n - 1)
t = [0] * (n - 1)
co = [0] * n
for i in range(n - 1):
    f[i], t[i] = map(int, input().split())
    co[f[i] - 1] += 1
    co[t[i] - 1] += 1
mid = 0
en = []
for i in range(n):
    if co[i] == 1:
        en.append(i + 1)
    elif co[i] > 2:
        if mid == 0:
            mid = i + 1
        else:
            print("No")
            flag = False
            break
if flag:
    print("Yes")
    if mid != 0:
        print(len(en))
        for i in range(len(en)):
            print(mid, en[i])
    else:
        print(1)
        print(en[0], en[1])