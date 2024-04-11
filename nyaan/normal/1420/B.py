t = int(input())
import bisect
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()
    point = [0]*31
    for i in range(31):
        point[i] = bisect.bisect_left(a, 2**i)
    count = [point[i+1] - point[i] for i in range(30)]
    ans = 0
    for i in range(30):
        ans += count[i] * (count[i] - 1) // 2
    print(ans)