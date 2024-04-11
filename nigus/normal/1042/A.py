n = int(input())
m = int(input())
A = []
for _ in range(0, n):
    A.append(int(input()))
print(max(max(A), (sum(A)+m+n-1)//n), max(A)+m)