n, m = map(int, input().split())
a = []
for i in range(n):
    k = input()
    a.append(k)
    if (k.find('S') > -1):
        stx = k.find('S')
        sty = i
    if (k.find('E') > -1):
        endx = k.find('E')
        endy = i
cmd = input()
ans = 0
for p1 in range(4):
    for p2 in range(4):
        for p3 in range(4):
            for p4 in range(4):
                if (p1 == p2 or p2 == p3 or p1 == p3 or p1 == p4 or p2 == p4 or p3 == p4):
                    continue
                else:
                    x = stx
                    y = sty
                    for i in range(len(cmd)):
                        if (int(cmd[i]) == p1):
                            x += 1
                        if (int(cmd[i]) == p2):
                            x -= 1
                        if (int(cmd[i]) == p3):
                            y += 1
                        if (int(cmd[i]) == p4):
                            y -= 1
                        if (x < m and y < n and x >= 0 and y >= 0):
                            if (x == endx and y == endy):
                                ans += 1
                                break
                            if (a[y][x] == '#'):
                                break
                        else:
                            break
print(ans)