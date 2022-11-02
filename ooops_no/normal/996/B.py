a=int(input())
x=list(map(int,input().split()))
BoOlIk=True
counter=1
if min(x)>a:
    counter+=min(x)//a*a
x.insert(0,0)
while BoOlIk:
    for i in range(1,a+1):
        if x[i]<counter:
            print(i)
            BoOlIk=False
            break
        counter+=1