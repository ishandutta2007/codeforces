import sys
input = sys.stdin.readline
inf = int(1e9)
for i in range(int(input())):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    l, r = 0, n - 1
    psum = [0] * (2 * k + 2)
    while l < r:
        s = arr[l] + arr[r]
        lb = min(arr[l], arr[r]) + 1
        rb = max(arr[l], arr[r]) + k
        psum[lb] += 1
        psum[rb + 1] -= 1
        psum[s] += 1
        psum[s + 1] -= 1
        l += 1
        r -= 1
    ans = 0
    for i in range(2, 2 * k + 1):
        psum[i] += psum[i - 1]
        ans = max(ans, psum[i])
    print(n - ans)