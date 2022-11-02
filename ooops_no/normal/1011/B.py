n,m=map(int,input().split())
l=list(map(int,input().split()))
listik=[]
numbers=[]
for i in l:
    if i in numbers:
        pass
    else:
        listik.append(l.count(i))
        numbers.append(i)
listik.sort()
maximum=0
x=False
for i in range(1,max(listik)+1):
    counter=0
    for j in listik[::-1]:
        if j//i>0:
            counter+=j//i
        else:
            if counter>=n:
                x=True
                break
    if counter>=n:
        if maximum<i:
            maximum=i
print(maximum)