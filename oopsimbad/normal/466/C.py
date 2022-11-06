n = int(input())
arr = [int(x) for x in input().split()]
sum = 0
for x in arr:
    sum += x

if sum % 3 != 0:
    print(0)
else:
    tar = sum // 3
    psum = [0]*n
    psum[0] = arr[0]
    for i in range(1,n):
        psum[i] = psum[i-1] + arr[i]
    
    ans = 0
    cnt = 0
    sum = 0
    for i in range(n-1,-1,-1):
        if psum[i] == tar:
            ans += cnt
        if i != n-1 and sum == tar:
            cnt += 1
        sum += arr[i]
        
    print(ans)