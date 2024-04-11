t = int(input())
for _ in range(t):
  n, k = map(int, input().split())
  print(min(n, n-n%k+k//2))