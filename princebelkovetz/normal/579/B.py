from sys import stdin, stdout
n=int(stdin.readline())
a=[]
b=[False]*2*n
for i in range(1,2*n):
    a+=[[int(f),i] for f in stdin.readline().split()]
    for j in range(i):
        a[-i+j].append(j)

a.sort(reverse=True)

ans=[]
for i in range(len(a)):
    if b[a[i][1]]==False and b[a[i][2]]==False:
        b[a[i][1]] = a[i][2]+1
        b[a[i][2]] = a[i][1]+1

print(*b)