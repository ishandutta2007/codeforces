n,m,k=map(int,raw_input().split())
a=1
b=1
lis=[1,1]
while True:
    if (b==m and a%2==1) or (b==1 and a%2==0):
        a+=1
    else:
        if a%2==1:
            b+=1
        else:
            b-=1
    if a==n+1:
        break
    lis.append(a)
    lis.append(b)
for i in range(k-1):
    print 2, lis[0+i*4], lis[1+i*4], lis[2+i*4], lis[3+i*4]
print n*m-2*(k-1),
for i in lis[4*(k-1):]:
    print i,