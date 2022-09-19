__author__ = 'Pavel Mavrin'

a = [int(x) for x in input().split()]
b = [1, 1, 2, 7, 4]

res = 1e100
for i in range(5):
    res = min(res, a[i] // b[i])

print(res)