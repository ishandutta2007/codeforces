import sys 
range = xrange
input = raw_input

inp = [int(x)-1 for line in sys.stdin for x in line.split()]
ii= 0
n,m = inp[0]+1,inp[1]+1
ii+=2

coupl = [[] for _ in range(n)]
for _ in range(m):
    u,v = inp[ii],inp[ii+1]
    ii+=2
    coupl[u].append(v)
    coupl[v].append(u)

found = [False]*n
count = 0
for root in range(n):
    if found[root]:
        continue
    cycle = True
    found[root]=True
    Q = [root]
    while Q:
        node = Q.pop()
        if len(coupl[node])!=2:
            cycle = False
        for nei in coupl[node]:
            if not found[nei]:
                found[nei] = True
                Q.append(nei)
    count += int(cycle)
print count