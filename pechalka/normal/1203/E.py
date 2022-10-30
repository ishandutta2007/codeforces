n = int(input())
A = list(map(int, input().split()))
B = [False] * 150001
for i in range(n):
  A[i] -= 1
A.sort()
i = 0
ans = 0
for j in range(150000):
  end = i
  while end < n and A[end] == j:
    end += 1
  cnt = end - i
  if (j > 0 and not B[j - 1] and cnt > 0):
    B[j - 1] = True
    cnt -= 1
    ans += 1
  if (not B[j] and cnt > 0):
    B[j] = True
    cnt -= 1
    ans += 1
  if (cnt > 0):
    B[j + 1] = True
    cnt -= 1
    ans += 1
  i = end
print(ans)