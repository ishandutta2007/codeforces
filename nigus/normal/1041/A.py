n = int(input())
A = list(map(int, input().split()))
print(max(A)-min(A)-n+1)