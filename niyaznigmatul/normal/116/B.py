
n, m = map(int, raw_input().split())
a = []
for i in range(n):
    a.append(raw_input())
ans = 0
for i in range(n):
    for j in range(m):
        if a[i][j] != 'W':
            continue
        ok = False
        for dx, dy in [[-1, 0], [0, -1], [1, 0], [0, 1]]:
            x = i + dx
            y = j + dy
            if x in range(0, n) and y in range(0, m):
                if a[x][y] == 'P':
                    ok = True
                    break
        if ok:
            ans += 1
print ans