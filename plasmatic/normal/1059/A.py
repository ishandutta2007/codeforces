import sys
lines = iter(sys.stdin)

def nexts():
    return next(lines)

def nextint():
    return int(nexts())

def snexts():
    return next(lines).split(' ')

def snextint():
    return map(int, snexts())

n, l, a = snextint()
cust = []

cust.append((0, 0))

for _ in range(n):
    t, tlen = snextint()
    cust.append((t, t + tlen))

cust.append((l, 0))
cust.sort(key=lambda tup: tup[0])

count = 0

# print(cust)

for ind, cus in enumerate(cust[:-1]):
    diff = cust[ind + 1][0] - cus[1]
    count += diff // a
    # print('for cus %s, diff of %d' % (str(cus), diff))

print(count)