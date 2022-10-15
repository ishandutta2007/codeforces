import sys
input = sys.stdin.readline
inf = int(1e18)
for i in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    mx = [(0, 0), (0, 0)]
    tans = (0, 0)
    for i in range(n):
        pp = arr[i] > 0
        ans = (mx[pp ^ 1][0] + 1, mx[pp ^ 1][1] + arr[i])
        tans = max(tans, ans)
        mx[pp] = max(mx[pp], ans)
    print(tans[1])