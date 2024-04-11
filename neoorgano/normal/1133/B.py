n, k = map(int, input().split())
arr = list(map(int, input().split()))
arr1 = [0] * k
for i in range(n):
    arr1[arr[i] % k] += 1
ans = 0
for i in range(1, (k + 1) // 2):
    ans += min(arr1[i], arr1[k - i])
ans += arr1[0] // 2
if k % 2 == 0:
    ans += arr1[(k + 1) // 2] // 2
print(ans * 2)