w = int(input())
for x in range(1, w - 1):
    y = w - x
    if x % 2 == 0 and y % 2 == 0:
        print("YES")
        exit(0)

print("NO")