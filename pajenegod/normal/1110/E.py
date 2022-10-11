import sys
range = xrange
input = raw_input

def printer(ans):
    print 'Yes' if ans else 'No'
    sys.exit()

n = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

if A[0] != B[0]:
    printer(0)

A = [A[i] - A[i - 1] for i in range(1,n)]
B = [B[i] - B[i - 1] for i in range(1,n)]

printer(sorted(A) == sorted(B))