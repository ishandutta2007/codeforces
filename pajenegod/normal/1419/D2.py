n = int(input())
arr = list(map(int, input().split()))
res = [0] * n
arr.sort()
res[1::2] = arr[:n//2]
res[::2]  = arr[n//2:]

x = 0
for i in range(1, n-1):
    x += res[i-1] > res[i] < res[i+1]

print(x)
print(*res)