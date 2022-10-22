
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans=[]
    a=sorted(a)
    if n%2==0:
        for i in range(n//2):
            ans.append(a[n//2+i])
            ans.append(a[n//2-i-1])
    else:
        for i in range(n//2):
            ans.append(a[n//2-i])
            ans.append(a[n//2+1+i])
        ans.append(a[0])

    print(*ans)