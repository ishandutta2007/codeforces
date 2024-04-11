def gcd(a, b):
  if b == 0:
    return a
  return gcd(b, a % b)

n = int(input())
A = list(map(int, input().split()))
allgcd = 0
for x in A:
  allgcd = gcd(allgcd, x)
ans = 1
i = 2
while i * i <= allgcd:
  cnt = 0
  while allgcd % i == 0:
    cnt += 1
    allgcd /= i
  ans *= cnt + 1
  i += 1
if (allgcd > 1):
  ans *= 2
print(ans)