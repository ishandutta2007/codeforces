x=raw_input().split()
n=int(x[0])
m=int(x[1])
k=int(x[2])
lis=[]
mes=[0]*n
roinvo=[0]*m
for i in range(n):
    x=raw_input().split()
    for i in range(len(x)):
        x[i]=int(x[i])
    lis.append(x)
for i in range(k):
    x=raw_input().split()
    roinvo[int(x[1])-1]+=1
    mes[int(x[0])-1]-=1
for i in range(n):
    for k in range(m):
        mes[i]+=roinvo[k]*lis[i][k]
for i in mes:
    print i,