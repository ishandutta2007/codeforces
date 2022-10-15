n, a, b = map(int, raw_input().split())
h = map(int, raw_input().split())
h.sort()
print h[b] - h[b - 1]