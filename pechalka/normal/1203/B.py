q = int(input())
for query in range(q):
  n = int(input())
  A = []
  was = dict()
  B = list(map(int, input().split()))
  for i in range(4 * n):
    x = B[i]
    if (x not in was) or (was[x] == 0):
      was[x] = 1
      A.append(x)
    else:
      was[x] = 0
  A.sort()
  if (len(A) != 2 * n):
    print("NO")
    continue
  S = [A[i] * A[-i - 1] for i in range(n)]
  if max(S) != min(S):
    print("NO")
  else:
    print("YES")