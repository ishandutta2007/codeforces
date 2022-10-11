import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

# First player wins?
def solve(A):
    zeros = A.count(0)
    if zeros>n//2:
        return False
    if zeros>0:
        return True

    B = [a-1 for a in A]
    return solve(B)

if solve(A):
    print 'Alice'
else:
    print 'Bob'