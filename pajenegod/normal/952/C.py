import sys
range = xrange
input = raw_input

def check(A):
    for i in range(len(A)-1):
        if abs(A[i]-A[i+1])>1:
            print('NO')
            sys.exit()


n = int(input())

A = [int(x) for x in input().split()]
check(A)


B = []

while A:
    check(A)
    a = max(A)
    i = 0
    while A[i]!=a:
        i+=1
    del A[i]
    B.append(a)
    check(B)
check(A)
check(B)

B = list(reversed(B))

print('YES')