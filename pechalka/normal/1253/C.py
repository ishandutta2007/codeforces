n, m = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
ans = [0] * n
prefsum = [0] * m
prefsum[0] = A[0]
ans[0] = A[0]
for i in range(1, n):
  ans[i] = ans[i - 1] + prefsum[i % m] + A[i]
  prefsum[i % m] += A[i]
print(*ans)