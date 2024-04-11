for _ in range(int(input())):
    n=int(input())
    ans=[]
    for i in range(2,n):
        if i*i>=n: break
        if n%i==0:
            ans.append(i)
            n//=i
        if len(ans)==2:
            ans.append(n)
            break
    if len(ans)==3:
        print('YES')
        print(*ans)
    else:
        print('NO')