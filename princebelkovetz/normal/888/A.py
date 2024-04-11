from sys import stdin, stdout
n=int(stdin.readline())
ans=0
a=[int(i) for i in stdin.readline().split()]
for i in range(1,n-1):
    if (a[i-1]<a[i] and a[i+1]<a[i]) or (a[i-1]>a[i] and a[i+1]>a[i]):
        ans+=1
stdout.write(str(ans))