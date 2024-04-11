import math
x=int(input())
sums=0
max_ele=[]
max_kol=[]
for i in range(x):
    l1=list(map(int,input().split()))
    max_ele+=[max(l1[1:])]
    max_kol+=[l1[0]]
max_el=max(max_ele)
indexik=max_ele.index(max_el)
del max_kol[indexik]
del max_ele[indexik]
for i in range(x-1):
    sums+=max_kol[i]*(max_el-max_ele[i])
print(sums)