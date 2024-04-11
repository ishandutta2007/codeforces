t = int(input())
for query in range(t):
  n, a, b = map(int, input().split())
  s = input()
  A = list()
  ln = 1
  j = 1
  while j < n:
    if s[j] == s[j - 1]:
      ln += 1
    else:
      A.append(ln)
      ln = 1
    j += 1
  A.append(ln)
  if (len(A) == 1):
    print(a * n + b * n + b)
  else:
    ans = A[0] * b + n * a
    i = 1
    while i + 1 < len(A):
      if i % 2 == 1:
        ans += (A[i] + 1) * 2 * b + a
      else:
        ans += (A[i] - 1) * b + min(a, (A[i] - 1) * b - a)
      i += 1
    ans += A[-1] * b + a
    print(ans)