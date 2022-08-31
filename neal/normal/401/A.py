_, X = [int(_) for _ in input().split()]
total = sum(int(_) for _ in input().split())
print((abs(total) + X - 1) // X)