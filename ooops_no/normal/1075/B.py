a,b=map(int,input().split())
listik1=list(map(int,input().split()))
listik2=list(map(int,input().split()))
residents=[]
taxi=[[],[]]
for _ in range(a+b):
    if listik2[_]==0:
        residents.append(listik1[_])
    else:
        taxi[0].append(listik1[_])
taxi[1]=[int(0)for i in range(b)]
if b==1:
    print(a)
else:
    counter=0
    for _ in range(b):
        while True:
            if counter==a:
                break
            if _==b-1:
                taxi[1][_]+=a-counter
                break
            if abs(taxi[0][_]-residents[counter])<=abs(taxi[0][_+1]-residents[counter]):
                taxi[1][_]+=1
                counter+=1
            else:
                break
    print(*taxi[1])