t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    i = 0
    while i < n and a[i] - b[i] == 0:
        i += 1
    if i == n:
        print('YES')
    else:
        cur = b[i] - a[i]
        f = False
        for j in range(i + 1, n):
            if b[j] - a[j] != cur:
                f = True
                i = j
                break
        while f and i < n and b[i] - a[i] == 0:
            i += 1
        if i == n and f and cur > 0:
            print('YES')
        elif f or cur < 0:
            print("NO")
        else:
            print("YES")