import sys,os,io
range = xrange

# INPUT
input_data = os.read(0,os.fstat(0).st_size)
input = io.BytesIO(input_data).readline


n,m = [int(x) for x in input().split()]
data = [input() for _ in range(n)]

rep = [-1]*(n+m)
for root in range(n+m):
    if rep[root]>=0:continue

    rep[root] = root

    Q = [root]
    while Q:
        node = Q.pop()

        if node<n:
            i = node
            for j in range(m):
                if rep[j+n]==-1 and data[i][j]=='=':
                    rep[j+n] = root
                    Q.append(j+n)
        else:
            j = node-n
            for i in range(n):
                if rep[i]==-1 and data[i][j]=='=':
                    rep[i] = root
                    Q.append(i)
assert(not any(r<0 for r in rep))

better = [[] for _ in range(n+m)]
for i in range(n):
    for j in range(m):
        if data[i][j]=='>':
            better[rep[j+n]].append(rep[i])
        elif data[i][j]=='<':
            better[rep[i]].append(rep[j+n])

counter = [0]*(n+m)
for ind in range(n+m):
    if rep[ind]==ind:
        for ind2 in better[ind]:
            counter[ind2] += 1

val = [-1]*(n+m)
found = sum(1 for ind in range(n+m) if rep[ind]==ind)

leaves = [ind for ind in range(n+m) if rep[ind]==ind and counter[ind]==0]
for ind in leaves:
    val[ind] = 1
while leaves:
    ind = leaves.pop()
    found -= 1
    v = val[ind]
    for ind2 in better[ind]:
        if ind2==ind:
            print 'No'
            sys.exit()
        val[ind2] = max(val[ind2],v+1)
        counter[ind2] -= 1
        if counter[ind2]==0:
            leaves.append(ind2)

val = [val[rep[i]] for i in range(n+m)]
if found>0 or any(v<0 for v in val):
    print 'No'
else:
    print 'Yes'
    print ' '.join(str(x) for x in val[:n])
    print ' '.join(str(x) for x in val[n:n+m])