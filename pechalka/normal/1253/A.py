t = int(input())
for kekes in range(t):
  n = int(input())
  A = list(map(int, input().split()))
  B = list(map(int, input().split()))
  C = [B[i] - A[i] for i in range(n)]
  if len(set(C)) > 2:
    print("NO")
  else:
    j = n - 1
    while j > 0 and C[j] == 0:
      j -= 1
    i = 0
    while i < n - 1 and C[i] == 0:
      i += 1
    if (A == B) or (len(set(C[i:j + 1])) == 1 and max(C) > 0):
      print("YES")
    else:
      print("NO")