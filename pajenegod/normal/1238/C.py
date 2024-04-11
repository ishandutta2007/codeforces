import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
q = inp[ii]; ii += 1

ans = []
for _ in range(q):
    h = inp[ii]; ii += 1
    n = inp[ii]; ii += 1
    P = inp[ii + 1:ii + n]; ii += n
    
    if P and P[-1] == 1:
        p = P.pop()
        while P and P[-1] == p + 1:
            p = P.pop() 

    cost = 0
    while P:
        p = P.pop()
        par = 1
        while P and P[-1] == p + 1:
            p = P.pop()
            par ^= 1
        cost += par
    
    ans.append(cost)
print '\n'.join(str(x) for x in ans)