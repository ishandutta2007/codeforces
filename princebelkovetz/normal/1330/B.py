from sys import stdin,stdout
input=stdin.readline
print=stdout.write
for _ in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    x=max(a)
    ans=[]
    for i in range(2):
        if (len(set(a[:x]))==x and x*(x+1)//2==sum(a[:x])) and (len(set(a[x:]))==n-x and (n-x)*(n-x+1)//2==sum(a[x:])):
            ans.append([x,n-x])
        if x==n-x:
            break
        x=n-x
    print(str(len(ans))+'\n')
    for i in range(len(ans)):
        for j in range(len(ans[i])):
            print(str(ans[i][j])+' ')
        print('\n')