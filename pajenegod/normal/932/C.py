import sys
range = xrange
input = raw_input


N,A,B = [int(x) for x in input().split()]
k = 0

while N-A*k>= 0 and (N-A*k)%B != 0:
    k+=1
if N-A*k<0:
    print -1
    sys.exit()

q = (N-A*k)//B



ind = 0
U = []

for _ in range(k):
    for i in range(ind+1,ind+A):
        U.append(i)
    U.append(ind)
    ind+=A

for _ in range(q):
    for i in range(ind+1,ind+B):
        U.append(i)
    U.append(ind)
    ind+=B

print ' '.join(str(x+1) for x in U)