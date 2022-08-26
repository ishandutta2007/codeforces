def solve():
    n = int(input())
    arr = [0] * n
    used = [0] * (n + 1)
    cur = 0
    ad = 1
    for i, el in enumerate(map(int, input().split())):
        if el < cur or el > n:
            print(-1)
            return
        while ad <= n and used[ad] == 1:
            ad += 1
        if used[el] == 0:
            used[el] = 1
            arr[i] = el
            cur = el
        elif ad < el:
            used[ad] = 1
            arr[i] = ad
        else:
            print(-1)
            return
    print(*arr)
    return


t = int(input())
for _ in range(t):
    solve()