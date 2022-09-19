__author__ = 'Pavel Mavrin'

n, m = [int(x) for x in input().split()]
a = []
for i in range(m):
    a.append([int(x) - 1 for x in input().split()])

a.sort(key=lambda x: x[0] * n + x[1])
a.append([n - 1, n])

d = [[0, 1]]
r = 0
i = 0
while i < len(a):
    if a[i][0] == r:
        dd = []
        j = 0
        while i < len(a) and a[i][0] == r and j < len(d):
            if a[i][1] < d[j][0]:
                i += 1
            elif a[i][1] == d[j][0]:
                d[j][0] += 1
                if d[j][0] >= d[j][1]:
                    j += 1
                i += 1
            else:
                dd.append([d[j][0], a[i][1]])
                d[j][0] = a[i][1] + 1
                while j < len(d) and d[j][1] <= a[i][1] + 1:
                    j += 1
                if j < len(d):
                    d[j][0] = max(d[j][0], a[i][1] + 1)
        if j < len(d):
            dd.append([d[j][0], n])
        while i < len(a) and (a[i][0] == r):
            i += 1
        d = dd
        r += 1
        if len(d) == 0:
            break
    else:
        r = a[i][0]
        d = [[d[0][0], n]]
    #print(r, i, d)

if len(d) == 0 or d[len(d) - 1][1] < n:
    print(-1)
else:
    print(2 * (n - 1))