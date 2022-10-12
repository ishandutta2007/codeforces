per = [2, 4, 1, 3], [2, 4, 1, 3, 5], [2, 5, 1, 3, 6, 4], [2, 6, 3, 1, 4, 7, 5]
for tc in range(int(input())):
    n = int(input())
    if n <= 3:
        print(-1)
        continue

    ans = []
    while n >= 8:
        n -= 4
        ans.extend([i+len(ans) for i in per[0]])

    ans.extend([i+len(ans) for i in per[n-4]])
    print(*ans)