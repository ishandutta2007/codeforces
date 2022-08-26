def solve():
    n = int(input())
    a = list(map(int, input().split()))
    flag = n + 1
    for i in range(n):
        if a[i] < i:
            flag = i
            break
    for j in range(n - flag + 1):
        if a[n - 1 - j] < j:
            print('No')
            return
    print("Yes")

t = int(input())
for _ in range(t):
    solve()