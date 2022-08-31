t = int(input())

for i in range(t):
    n, k, d = map(int, input().split())
    arr = list(map(int, input().split()))
    sl = {i: 0 for i in range(1, k + 1)}
    c = 0
    for i in arr[:d]:
        if not sl[i]:
            c += 1
        sl[i] += 1
    l = 0
    m = c
    for r in range(d, n):
        sl[arr[l]] -= 1
        if not sl[arr[l]]:
            c -= 1
        if not sl[arr[r]]:
            c += 1
        sl[arr[r]] += 1
        if c < m:
            m = c
        l += 1
    print(m)