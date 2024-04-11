for t in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    idx = {} 
    for i in range(n):
        idx[a[i]] = []
    for i in range(n):
        idx[a[i]].append(i)
    ans = 0
    for x in idx: 
        S = 0
        for i in idx[x]:
            ans += S*(n-i)
            S += i+1
    print(ans)