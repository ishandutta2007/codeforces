for _ in range(int(input())):
    n,k=map(int,input().split())
    print('YES') if n%2==k%2 and n>=k*k else print('NO')