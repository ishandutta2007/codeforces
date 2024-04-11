q = raw_input().split()
n = int(q[0])
k = int(q[1])

mas = raw_input().split()
mas2 = [0] * 101

for i in mas:
    mas2[int(i)] += 1

ans = 0
for i in xrange(100, 0, -1):
    if(mas2[i] != 0):
        ans += mas2[i]
    if(ans >= k):
        break
print ans