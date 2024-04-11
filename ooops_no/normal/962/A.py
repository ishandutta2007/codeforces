import bisect
import math
x=int(input())
listik=[]
summa=0
for i in input().split():
    summa+=int(i)
    listik.append(summa)
summa=math.ceil(summa/2)
indexik=bisect.bisect(listik,summa)
if x==1:
    print(1)
else:
    if listik[indexik-1]<summa:
        print(indexik+1)
    else:
        print(indexik)