import sys
range = xrange
input = raw_input

n = int(input())

if n==1:
    print -1
    sys.exit()


inp = [int(x)-1 for line in sys.stdin for x in line.split()]
ii = 0
coupl = [[] for _ in range(n)]
for _ in range(n-1):
    u,v = inp[ii],inp[ii+1]
    ii+=2
    coupl[u].append(v)
    coupl[v].append(u)

root = 0
Q = [root]
unused = 0
depth = [-1]*n
found = [False]*n
order = []

found[root]=True
while Q:
    node=Q.pop()
    order.append(node)
    depth[node]=unused
    unused+=1
    for nei in coupl[node]:
        if not found[nei]:
            found[nei]=True
            Q.append(nei)

is_odd = [-1]*n

count = 0
for node in reversed(order):
    if node!=root and len(coupl[node])==1:
        is_odd[node]=True
    else:
        even_child = 0
        odd_child = 0
        for nei in coupl[node]:
            if depth[nei]>depth[node]:
                if is_odd[nei]:
                    odd_child+=1
                else:
                    even_child+=1
        count += even_child
        is_odd[node]=odd_child%2==0
if is_odd[root]:
    print -1
else:
    print count