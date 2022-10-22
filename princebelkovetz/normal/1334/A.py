from sys import stdin,stdout
input=stdin.readline
print=stdout.write
for _ in range(int(input())):
    n=int(input())
    ans='YES'
    p1,c1=map(int,input().split())
    for i in range(n-1):
        p,c = map(int,input().split())
        if p<p1 or c<c1 or ((c-c1)>(p-p1)) or c>p or c1>p1:
            ans = 'NO'
        p1=p
        c1=c
    if n == 1 and c1>p1:
        ans = 'NO'
    print(ans+'\n')