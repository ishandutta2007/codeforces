import sys
input = raw_input
range = xrange

n,K,V = [int(x) for x in input().split()]
    



A = [int(x) for x in input().split()]
Acop = A[:]

if (V%K)==0:
    asum = sum(A)
    if asum>=V:
        print 'YES'
        for i in range(1,n):
            A[0] += A[i]
            count = (A[i]+K-1)//K
            if count>0:
                print count,i+1,1
            A[i] = 0
        if V!=0:
            print V//K,1,2
        sys.exit()
    else:
        print 'NO'
        sys.exit()



B = [a%K for a in A]
take = [0]*n


BIG = 5001
found = [-1]*BIG
found[0] = -2
prev = [-1]*BIG
prev[0] = -2
used = [False]*BIG

for i in range(n):
    b = B[i]
    for j in range(BIG-1):
        if found[j]!=-1 and not used[j]:
            ind = (b+j)%K
            if found[ind]==-1:
                found[ind] = i
                prev[ind] = j
                used[ind] = True
    for j in range(BIG):
        used[j]=False

if found[V%K]==-1:
    print 'NO'
    sys.exit()
tanks = []
ind = V%K
while prev[ind]!=-2:
    tanks.append(found[ind])
    ind = prev[ind]

master = tanks[0]
tanks = set(tanks)
for i in range(n):
    if i not in tanks:
        other = i
        break
else:
    other = -1
outp = []
for i in range(n):
    if i==master or i==other:
        continue
    if i in tanks:
        A[master] += A[i]
        count = (A[i]+K-1)//K
        if count>0:
            outp.append(" ".join([str(count),str(i+1),str(master+1)]))
        take[i] += count
        A[i] = 0
    else:
        A[other] += A[i]
        count = (A[i]+K-1)//K
        take[i] += count
        if count > 0:
            outp.append(" ".join([str(count),str(i+1),str(other+1)]))
        A[i] = 0
if other==-1:
    for i in range(n):
        if i!=master:
            other=i
            break

if A[master]+A[other]<V:
    print 'NO'
    
    sys.exit()
elif A[master]+A[other]==V:
    print 'YES'
    for s in outp:
        print s
    count = (A[other]+K-1)//K
    if count>0:
        print count,other+1,master+1
    sys.exit()
else:
    count = A[other]//K
    if count>0:
        A[master] += K*(count)
        A[other]%=K
        outp.append(" ".join([str(count),str(other+1),str(master+1)]))
    if A[master]>V:
        count = (A[master]-V)//K
        if count>0:
            outp.append(" ".join([str(count),str(master+1),str(other+1)]))
        A[master]-=count*K
        A[other]+=count*K
    if A[master]==V:

        print 'YES'
        for s in outp:
            print s
    else:
        print 'NO'