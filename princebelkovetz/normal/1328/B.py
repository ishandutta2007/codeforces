for _ in range(int(input())):
    n,m=map(int,input().split())
    i=1
    while i*(i-1)/2<m:
        i+=1
    j=m-((i-1)*(i-2)//2)
    ans='a'*(n-i)+'b'+'a'*(i-j-1)+'b'+'a'*(j-1)
    print(ans)