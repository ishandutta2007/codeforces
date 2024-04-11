import sys

s = sys.stdin.read()
inp = []
numb = 0
 
for i in range(len(s)):
    if s[i]>='0':
        numb = 10*numb + ord(s[i])-48
    else:
        inp.append(numb)
        numb = 0
if s[-1]>='0':
    inp.append(numb)

ii = 0
n = inp[ii]
ii+=1
m = inp[ii]
ii+=1
k = inp[ii]
ii+=1

coupl = [[] for _ in range(n)]
for _ in range(m):
    u = inp[ii]-1
    ii += 1
    v = inp[ii]-1
    ii += 1

    coupl[u].append(v)
    coupl[v].append(u)

P = [-1]*n
D = [1]*n
found = [False]*n

cycle_nodes = []

Q = [0]
while Q:
    node = Q.pop()
    if found[node]:
        continue
    found[node] = True
    found_any = False
    for nei in coupl[node]:
        if not found[nei]:
            P[nei] = node
            D[nei] = D[node]+1
            Q.append(nei)
            found_any = True
    if not found_any:
        cycle_nodes.append(node)

i = max(range(n),key=lambda i:D[i])
if k*D[i]>=n:
    print('PATH')
    print(D[i])
    out = []
    while i!=-1:
        out.append(i)
        i = P[i]
    print(' '.join(str(x+1) for x in out))
elif len(cycle_nodes)>=k:
    print('CYCLES')
    out = []
    for i in cycle_nodes[:k]:
        minD = min(D[nei] for nei in coupl[i] if (D[i] - D[nei] + 1)%3!=0) 
        tmp = []
        if minD == D[i]-1:
            a,b = [nei for nei in coupl[i] if (D[i] - D[nei] + 1)%3==0][:2]
            if D[a]<D[b]:
                a,b = b,a
            tmp.append(i)
            while a!=b:
                tmp.append(a)
                a = P[a]
            tmp.append(a)
        else:
            while D[i]!=minD:
                tmp.append(i)
                i = P[i]
            tmp.append(i)
        out.append(str(len(tmp)))
        out.append(' '.join(str(x+1) for x in tmp))
    print('\n'.join(out))
else:
    print(-1)