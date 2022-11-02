x=int(input())
a=sorted(list(map(int,input().split())))
i=0
counter=0
while i<x-1:
    if a[i]+1!=a[i+1]:
        counter+=a[i+1]-a[i]-1
    i+=1
print(counter)