ans=[]
for _ in range(int(input())):
    n=int(input())
    a=[int(i)for i in input().split()]
    if n==1 and a[0]%2==0:
        ans.append('NO')
    elif sum(a)%2==0:
        x=a[0]%2
        for i in range(1,n):
            if a[i]%2!=x:
                ans.append('YES')
                break
            elif i==n-1:
                ans.append('NO')
    else:
        ans.append('YES')
for i in range(len(ans)):
    print(ans[i])