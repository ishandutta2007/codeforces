n = int(input().strip())
data = list(map(int, input().split()))

s = set()
prev = dict()
ans = 0
for val in data:
    if val in prev:
        ans -= prev[val]
    prev[val] = len(s)
    ans += prev[val]
    s.add(val)

print (ans)