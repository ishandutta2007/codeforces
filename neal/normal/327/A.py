N = int(raw_input())
numbers = map(int, raw_input().split())
ones = len(filter(lambda x: x == 1, numbers))
numbers = map(lambda x: +1 if x == 0 else -1, numbers)

best, prefix = -1e100, 0

for i in xrange(N):
    prefix = max(prefix, 0)
    prefix += numbers[i]
    best = max(best, prefix)

print ones + best