t = int(input())
for qury in range(t):
  A = [0] * 3
  A[0], A[1], n = map(int, input().split())
  A[2] = A[0] ^ A[1]
  print(A[n % 3])