n,m=map(int,input().split())
listik=list(map(int,input().split()))
maximum=0
for i in listik:
    if listik.count(i)>maximum:
        maximum=listik.count(i)
if maximum%m==0:
    number=maximum//m
else:
    number=maximum//m+1
print(len(set(listik))*number*m-len(listik))