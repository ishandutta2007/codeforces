n, d = map(int, input().split())
data = list(map(int, input().split()))

pos = set([x - d for x in data] + [x + d for x in data])

isValid = lambda x: min(abs(x-p) for p in data) == d
ans = len(list(filter(isValid, list(pos))))

print (ans)