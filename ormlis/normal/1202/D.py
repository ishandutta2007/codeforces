def solve(n):
    cur = 2
    while cur * (cur + 1) // 2 <= n:
        cur += 1
    ans = [cur]
    if cur * (cur - 1) // 2 != n:
        ans.extend(solve(n - cur * (cur - 1) // 2))
    return ans


for _ in range(int(input())):
    ans = solve(int(input()))
    print('1', end='')
    for i in range(1, len(ans)):
        print('3' * (ans[i - 1] - ans[i]) + '1', end='')
    print('3' * ans[-1] + '7')