a=int(input())
b=list(map(int,input().split()))
c=int(input())
d=list(map(int,input().split()))
b.sort()
d.sort()
counter=0
for i in b:
    for j in d:
        if abs(i-j)<=1:
            counter+=1
            d.remove(j)
            break
print(counter)