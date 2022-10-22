for _ in range(1):
    n = int(input())
    b = sorted([int(i) for i in input().split()])
    a = [0] * n
    cur = 0
    for i in range(0, n, 2):
        a[cur] = b[i]
        cur += 1
    for i in range(n - 1 - n % 2, 0, -2):
        a[cur] = b[i]
        cur += 1
    check = True
    for i in range(-1, n - 1):
        if a[i] >= a[i - 1] + a[i + 1]:
            check = False
            break
    if check:
        print("YES")
        print(*a)
    else:
        print("NO")