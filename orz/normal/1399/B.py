t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    aa = min(a)
    bb = min(b)
    ans = 0
    for j in range(n):
        ans += max(a[j] - aa, b[j] - bb)
    print(ans)