n, k1, k2 = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ans = [abs(x-y) for x, y in zip(a, b)]
ans.sort()
for i in range(k1+k2):
    ans[-1] = abs(ans[-1] - 1)
    j = -1
    while j > -n and ans[j] < ans[j-1]:
        ans[j], ans[j-1] = ans[j-1], ans[j]
        j -= 1

ans = sum(map(lambda x: x*x, ans))
print (ans)