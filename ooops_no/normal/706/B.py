import bisect
x=int(input())
a=sorted(map(int,input().split()))
b=int(input())
for _ in range(b):
    print(bisect.bisect(a,int(input())))