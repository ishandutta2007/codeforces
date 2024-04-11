n,m=map(int,input().split())
listik=sorted(list(map(int,input().split())))
summa=0
last=0
for i in range(n):
    if listik[i]>last:
        last+=1
        summa+=1
print(sum(listik)-n-listik[-1]+summa)