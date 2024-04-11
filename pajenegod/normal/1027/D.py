import sys
range = xrange
input = sys.stdin.readline

n = int(input())
C = [int(x) for x in input().split()]
A = [int(x)-1 for x in input().split()]

times_found = [0]*n
fixed = [False]*n

cost = 0

for root in range(n):
    if fixed[root]:continue
    node = root

    times_found[node] += 1
    path = [node]
    node = A[node]
    while not fixed[node]:
        if times_found[node]==2:
            break
        path.append(node)
        times_found[node] += 1
        node = A[node]
    else:
        for node in path:
            fixed[node]=True
        continue
     
    cost += min(C[i] for i in path if times_found[i]==2)
    
    for node in path:
        fixed[node]=True
print cost