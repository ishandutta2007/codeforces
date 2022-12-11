n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
su = []
q = 0
for i in range(n):
    q += a[i]
    su.append(q)
cur_i = 0
for i in range(m):
    num = b[i]
    while (num > su[cur_i]):
        cur_i += 1
    if (cur_i == 0):
        f = 0
    else:
        f = su[cur_i - 1]
    print(cur_i + 1, num - f)