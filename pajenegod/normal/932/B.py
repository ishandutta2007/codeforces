import sys
range = xrange
input = raw_input

prod = [0]*(10**6+1)
prod[0] = 1
for i in range(1,10):
    prod[i] = i
for i in range(10,10**6+1):
    prod[i] = prod[i%10] * prod[i//10]
prod[0] = 1



g = [0]*(10**6+1)
for i in range(10):
    g[i] = i

for i in range(10,10**6+1):
    g[i] = g[prod[i]]



Xi = [[0]*(10**6+1) for _ in range(1,10)]
for j in range(1,10):
    A = Xi[j-1]
    for i in range(1,10**6+1):
        A[i] = A[i-1] + int(g[i]==j)
q = int(input())

inp = [int(x) for line in sys.stdin for x in line.split()]
ind = 0

for _ in range(q):
    l = inp[0+ind]
    r = inp[1+ind]
    k = inp[2+ind]
    ind += 3
    A = Xi[k-1]
    print A[r]-A[l-1]