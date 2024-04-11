n = int(input())
A = list(map(int, input().split()))
for i in range(n):
  A[i] = [-A[i], i]
A.sort()
ans = 0
for i in range(n):
  ans += i * (-A[i][0]) + 1
print(ans)
for x in A:
  print(x[1] + 1, end=' ')