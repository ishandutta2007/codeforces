l=[int(j)for j in input().split()]
k=[int(i)for i in input().split()]
w=l[1]-1
q=l[1]
a=0
p=0
if k[w]==0:
    while True:
        a+=1
        try:
            if k[w-a]==k[w-p]:
                p+=1
                q-=1
            else:
                q-=1
                a=0
                p=0
                break
        except IndexError:
            q=0
            break
else:
    while True:
        a+=1
        try:
            if k[w+a]==k[w+p]:
                p+=1
                q+=1
            else: 
                break
        except IndexError:
            break
print(q)