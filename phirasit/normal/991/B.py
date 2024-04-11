n = int(input())
data = list(map(int, input().split()))

data.sort()

req = 4.5 * n
ans = 0
while sum(data) < req:
    data = data[1:] + [5]
    ans += 1

print(ans)