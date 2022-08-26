def solve():
    s = list(map(int, input()))
    ans = [[0] * 10 for i in range(10)]
    for i in range(10):
        for j in range(i + 1):
            arr = [1000] * 10
            for i1 in range(10):
                for j1 in range(i1 == 0, 10):
                    st = (i * i1 + j * j1) % 10
                    arr[st] = min(arr[st], i1 + j1 - 1)
            for e in range(1, len(s)):
                cur = (s[e] - s[e - 1]) % 10
                if arr[cur] != 1000:
                    ans[i][j] += arr[cur]
                else:
                    ans[i][j] = -1
                    break
            ans[j][i] = ans[i][j]
    for i in range(10):
        print(*ans[i])


solve()