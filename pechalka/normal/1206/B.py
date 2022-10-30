n = int(input())
A = list(map(int, input().split()))
ans = 0
cnt = 0
cnt0 = 0
for x in A:
  if x == 0:
    ans += 1
    cnt0 += 1
  elif x > 0:
    ans += x - 1
  else:
    ans += -x - 1
    cnt += 1
if cnt % 2 == 1 and cnt0 == 0:
  ans += 2
print(ans)