from sys import stdin, stdout
t=int(stdin.readline())
for i in range(t):
    n,x=map(int,stdin.readline().split())
    a=[int(i) for i in stdin.readline().split()]
    b=[0]*1000
    for i in range(len(a)):
        b[a[i]]=1
    i=1
    while x>0:
        if b[i]==0:
            x-=1
            b[i]=1
        i+=1
    for i in range(1,len(b)):
        if b[i]==0:
            print(i-1)
            break