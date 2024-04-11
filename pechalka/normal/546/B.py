n = int(input())
cnt = dict()
A = list(map(int, input().split()))
for x in A:
    if x not in cnt:
        cnt[x] = 0
    cnt[x] += 1
ans = 0
for i in range(1, 2 * n + 1):
    if i in cnt:
        for j in range(cnt[i] - 1):
            ans += 1
            if i + 1 not in cnt:
                cnt[i + 1] = 0
            cnt[i + 1] += 1
print(ans)