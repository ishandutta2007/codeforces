a,b=map(int,input().split())
l=set(map(int,input().split()))
l1=[]
i=1
while i<=b:
    if i not in l:
        b-=i
        if b<0:
            break
        else:
            l1+=[str(i)]
    i+=1
print(len(l1))
print(' '.join(l1))