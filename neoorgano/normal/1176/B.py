t = int(input())
for i in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    arr1 = [0, 0, 0]
    for j in range(n):
        arr1[arr[j] % 3] += 1
    ans = arr1[0]
    ans1 = ans
    ans1 += arr1[1] // 3
    ans1 += arr1[2] // 3
    k = min(arr1[1], arr1[2])
    ans += k
    arr1[1] -= k
    arr1[2] -= k
    ans += arr1[1] // 3
    ans += arr1[2] // 3
    print(max(ans, ans1))