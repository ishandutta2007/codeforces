n, m = map(int, input().split())
A = [list(map(int, input().split())) for i in range(n)]
ans = []
for i in range(n - 1):
  for j in range(m - 1):
    if A[i][j] == 1 and A[i + 1][j] == 1 and A[i][j + 1] == 1 and A[i + 1][j + 1] == 1:
      ans.append([i, j])
B = [[0] * m for i in range(n)]
for x in ans:
  B[x[0]][x[1]] = 1
  B[x[0] + 1][x[1]] = 1
  B[x[0]][x[1] + 1] = 1
  B[x[0] + 1][x[1] + 1] = 1
if (A != B):
  print(-1)
else:
  print(len(ans))
  for x in ans:
    print(x[0] + 1, x[1] + 1)