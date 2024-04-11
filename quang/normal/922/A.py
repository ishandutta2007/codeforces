x, y = map(int, input().split())
print ("No" if y < 1 or (y == 1 and x > 0) or x + 1 < y or (x - y - 1) % 2 else "Yes")