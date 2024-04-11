(n, m) = map(int, input().split())
a = dict()
b = dict()
for i in range(0, 5):
    a[i] = ((n - i) // 5 + 1)
    b[i] = ((m - i) // 5 + 1)

total = 0
a[0] -= 1
b[0] -= 1

for i in range(0, 5):
    total += a[i] * (b[(5 - i) % 5])

print(total)