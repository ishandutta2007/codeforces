t = int(input())
for query in range(t):
  s, i, e = map(int, input().split())
  #x > (i + e - s) / 2
  print(max(0, e - max(-1, (i + e - s) // 2)))