n, l, r = map(int, input().split())
minsum = n - l + 2 ** l - 1
maxsum = 2 ** r - 1 + (n - r) * 2 ** (r - 1)
print(minsum, maxsum)