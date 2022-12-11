n = int(input().strip())

def C(n, r):
    c = 1
    for i in range(r):
        c = c * (n-i)
    for i in range(r):
        c = c // (i+1)
    return c

def calc(n, r):
    if n < 0: return 0
    return C(n+r-1, r-1)

ans = 0

# case 1: d = 0
for i in range(5):
    ans += calc(n-i, 2)

for i in range(4):
    ans += calc(n-i, 2)

for i in range(5):
    for j in range(4):
        ans -= calc(n-i-j, 1)

# case 2: d > 0
# a < 5, b < 8
for i in range(5):
    for j in range(8):
        ans += calc(n-i-j-1, 2)

print (ans)