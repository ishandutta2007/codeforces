q = int(input())

for i in range(q):
    n = int(input())
    if n < 4:
        print(4 - n)
    else:
        print(2 * ((n - 1) // 2 + 1) - n)