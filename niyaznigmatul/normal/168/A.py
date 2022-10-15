n, x, y = map(int, raw_input().split())
print max(0, (n * y + 99) // 100 - x)