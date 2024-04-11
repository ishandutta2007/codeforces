from sys import stdin,stdout
input=stdin.readline
print=stdout.write
for _ in range(int(input())):
    n,m=map(int, input().split())
    ans=''
    ans+=('B'*m+'\n')
    ans*=(n-1)
    ans+=('B'*(m-1)+'W'+'\n')
    print(str(ans))