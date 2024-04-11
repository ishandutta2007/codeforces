n = int(input())
a = [int(x) for x in input().split()]

m = {}
for i in range(n):
    if not a[i] in m:
        m[a[i]] = []
    m[a[i]].append(i)

v1 = [0]*n
v2 = [0]*n
for x in m:
    for i in range(len(m[x])):
        v1[m[x][i]] = i+1
        v2[m[x][i]] = len(m[x])-i

BIT = [0] * (n+5)
def get(i):
    res = 0
    while i > 0:
        res += BIT[i]
        i -= i & -i
    return res

def add(i):
    i += 1
    while i < n+5:
        BIT[i] += 1
        i += i & -i

ans = 0
for i in range(n-1, -1, -1):
    ans += get(v1[i])
    add(v2[i])

print(ans)