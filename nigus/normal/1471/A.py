t = int(input())
for _ in range(t):
    (n, k) = map(int, input().split())
    A = list(map(int, input().split()))
    print((sum(A)+k-1)//k, sum((i+k-1)//k for i in A))