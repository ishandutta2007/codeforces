t = int(input())
for query in range(t):
  a, b, c = map(int, input().split())
  ans = 0
  for cnt1 in range(101):
    for cnt2 in range(101):
      if a >= cnt1 and b >= cnt1 * 2 + cnt2 and c >= cnt2 * 2:
        ans = max(ans, cnt1 * 3 + cnt2 * 3)
  print(ans)