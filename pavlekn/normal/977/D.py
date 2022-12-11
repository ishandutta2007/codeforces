n = int(input())
a = list(map(int, input().split()))
count = []
for i in range(n):
    x = 1
    c = 0
    while (a[i] % x == 0):
        x *= 3
        c += 1
    c -= 1
    count.append([-c, a[i]])
count.sort()
for i in range(n):
    print(count[i][1], end=' ')