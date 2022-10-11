import sys
range = xrange
input = raw_input

s = sys.stdin.read()
inp = []
numb = 0
sign = 1
 
for i in range(len(s)):
    if s[i]>='0':
        numb = 10*numb + ord(s[i])-48
    else:
        if s[i]=='-':
            sign = -1
        else:
            inp.append(sign*numb)
            numb = 0
            sign = 1
if s[-1]>='0':
    inp.append(sign*numb)

ii = 0

n = inp[ii]
ii +=1
m = inp[ii]
ii += 1

coupl = [[] for _ in range(n)]
cost = [[] for _ in range(n)]

for _ in range(m):
    u,v,c = inp[ii]-1,inp[ii+1]-1,inp[ii+2]
    ii+=3
    coupl[u].append(v)
    cost[u].append(c)


vals = [0]
for v in sorted(inp[4::3]):
    if (not vals) or (v!=vals[-1]):
        vals.append(v)

a = 0
b = len(vals)-1

while a!=b:
    mid_index = (a+b)//2
    mid = vals[mid_index]

    indeg = [0]*n
    rem_indeg = []
    removed = 0

    for i in range(n):
        for j in range(len(coupl[i])):
            if cost[i][j]>mid:
                indeg[coupl[i][j]] += 1
    
    for i in range(n):
        if indeg[i]==0:
            rem_indeg.append(i)

    while rem_indeg:
        node = rem_indeg.pop()
        removed += 1

        for j in range(len(coupl[node])):
            if cost[node][j]>mid:
                nei = coupl[node][j]
                indeg[nei] -= 1
                if indeg[nei]==0:
                    rem_indeg.append(nei)

    if removed==n:
        b = mid_index
    else:
        a = mid_index+1

prio = []
mid = vals[a]

indeg = [0]*n
rem_indeg = []

for i in range(n):
    for j in range(len(coupl[i])):
        if cost[i][j]>mid:
            indeg[coupl[i][j]] += 1

for i in range(n):
    if indeg[i]==0:
        rem_indeg.append(i)

while rem_indeg:
    node = rem_indeg.pop()
    prio.append(node)

    for j in range(len(coupl[node])):
        if cost[node][j]>mid:
            nei = coupl[node][j]
            indeg[nei] -= 1
            if indeg[nei]==0:
                rem_indeg.append(nei)

node_prio = [-1]*n
for i in range(n):
    node_prio[prio[i]] = i

output = []
ii = 2
for _ in range(m):
    u,v,c = inp[ii]-1,inp[ii+1]-1,inp[ii+2]
    ii += 3
    if node_prio[u]>node_prio[v]:
        output.append(_)
print mid,len(output)
print ' '.join(str(x+1) for x in output)