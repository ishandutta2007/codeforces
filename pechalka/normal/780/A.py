n = int(input())
A = map(int, input().split())
before = set()
cnt = 0
ans = 0
for x in A:
    if x in before:
        cnt -= 1
    else:
        cnt += 1
        before.add(x)
    ans = max(ans, cnt)
print(ans)