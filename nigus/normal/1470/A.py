T = int(input())

for _ in range(T):
  (n, m) = map(int, input().split())
  K = list(map(int, input().split()))
  C = list(map(int, input().split()))
  K.sort()
  L = 1
  R = m+1
  while L < R-1:
    mid = (L+R)//2
    yes = 1
    for i in range(mid):
      if n-i-1 < 0:
        yes = 0
        break
      if K[n-i-1]-1 < i:
        yes = 0
    if yes:
      L = mid
    else:
      R = mid
  ans = 0
  for i in range(n):
    if n-i-1 < L:
      ans += C[n-i-1]
    else:
      ans += C[K[i]-1]
  print(ans)