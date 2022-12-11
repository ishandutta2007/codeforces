n = input()
data = list(map(int, input().split()))

ans = max([data.count(i) for i in data])
print (ans)