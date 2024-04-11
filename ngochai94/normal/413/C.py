x=raw_input().split()
n=int(x[0])
m=int(x[1])
lis=raw_input().split()
for i in range(n):
    lis[i]=int(lis[i])
au=raw_input().split()
auc=[]
for i in au:
    auc.append(lis[int(i)-1])
cur=sum(lis)-sum(auc)
auc.sort()
for i in range(m):
    if cur<auc[-1]:
        cur+=auc[-1]
    else:
        cur*=2
    auc=auc[:-1]
print cur