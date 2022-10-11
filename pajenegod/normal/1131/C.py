input()
A=sorted(map(int,input().split()))
print(*A[::2],*A[1::2][::-1])