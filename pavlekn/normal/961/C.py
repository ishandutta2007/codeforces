n = int(input())
a = []
for c in range(4):
    q = []
    for i in range(n):
        q.append(input())
    a.append(q)
    if (c != 3):
        s = input()
ans = 10 ** 9
for k in range(6):
    if (k == 0):
        a0 = [1, 2]
        a1 = [3, 4]
    elif (k == 1):
        a0 = [1, 3]
        a1 = [2, 4]
    elif (k == 2):
        a0 = [1, 4]
        a1 = [2, 3]
    elif (k == 3):
        a0 = [2, 3]
        a1 = [1, 4]
    elif (k == 4):
        a0 = [2, 4]
        a1 = [1, 3]
    elif (k == 5):
        a0 = [3, 4]
        a1 = [1, 2]
    count = 0
    for i in range(1, 5):
        for x in range(n):
            for y in range(n):
                if (i in a0):
                    if ((x + y) % 2 == 0 and a[i - 1][x][y] == '1'):
                        count += 1
                    elif ((x + y) % 2 == 1 and a[i - 1][x][y] == '0'):
                        count += 1
                else:
                    if ((x + y) % 2 == 0 and a[i - 1][x][y] == '0'):
                        count += 1
                    elif ((x + y) % 2 == 1 and a[i - 1][x][y] == '1'):
                        count += 1
    ans = min(ans, count)
print(ans)