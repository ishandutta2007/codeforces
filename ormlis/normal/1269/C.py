def solve():
    n, k = map(int, input().split())
    arr = list(map(int, input().strip()))
    f = False
    for i in range(k, n):
        if arr[i] > arr[i % k]:
            f = True
        elif arr[i] < arr[i % k]:
            break
    if f:
        for i in range(k - 1, -1, -1):
            if arr[i] != 9:
                arr[i] += 1
                break
            else:
                arr[i] = 0

    print(n)
    print(*map(lambda x: arr[x % k], range(n)), sep='')

solve()