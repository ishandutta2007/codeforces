n = int(input().strip())
data = list(map(int, input().split()))

data = [x for x in data if x < 0 or int(x ** 0.5) ** 2 != x]
print (max(data))