q = int(input())
for query in range(q):
  n = int(input())
  A = list(map(int, input().split()))
  num = 0
  while A[num] != 1:
    num += 1
  if A[num:] + A[:num] == [i for i in range(1, n + 1)] or A[num:] + A[:num] == [1] + [i for i in range(n, 1, -1)]:
    print("YES")
  else:
    print("NO")