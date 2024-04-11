__author__ = 'Pavel Mavrin'

n = int(input())
a = [int(x) for x in input().split()]

s = 0
res = 0
for i in a:
    if i == 0:
        res += s
    else:
        s += 1

print(res)