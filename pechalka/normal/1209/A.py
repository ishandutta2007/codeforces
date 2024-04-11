n = int(input())
A = list(map(int, input().split()))
A.sort()
ans = 1
for i in range(1, n):
  ok = False
  for j in range(i):
    if A[i] % A[j] == 0:
      ok = True
  if not ok:
    ans += 1
print(ans)