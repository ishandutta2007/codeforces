a=int(input())
o=[]
q=0
d=1
for i in range(a):
    x=sum([int(i)for i in input().split()])
    if q==0:
        j=x
    o+=[x]
    p=sorted(o)
    q+=1
while True:
    if p[-(d)]==j:
        print(d)
        break
    else:
        d+=1