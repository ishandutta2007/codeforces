n, m = map(int, input().split())
A = [0] * n
s = 0
for i in range(n):
    a, b = map(int, input().split())
    A[i] = a - b
    s += a
A.sort()
ans = 0
while len(A) > 0 and s > m:
    s -= A[-1]
    A.pop()
    ans += 1
if s > m:
    print(-1)
else:
    print(ans)