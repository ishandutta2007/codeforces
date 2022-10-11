import sys
range = xrange
input = raw_input

def solve(A):
    n = len(A)
    
    rotations = []
    def rotate(i):
        assert(0 <= i < n - 2)
        rotations.append(i)
        A[i + 1], A[i + 2], A[i] = A[i:i + 3] 

    for i in range(n - 2):
        ind = i
        for j in range(i, n):
            if A[ind] > A[j]:
                ind = j
        while ind >= i + 2:
            rotate(ind - 2)
            ind -= 2
        if ind == i + 1:
            rotate(i)
            rotate(i) 
    assert(len(rotations) <= n*n)
    assert A[:-2] == sorted(A[:-2]) and max(A[:-2]) <= min(A[-2:])

    if A[-3] == A[-1] and not A[-3] <= A[-2] <= A[-1]:
        rotate(n - 3)

    if A == sorted(A):
        print len(rotations)
        print ' '.join(str(x + 1) for x in rotations)
        return True
    
    i = n - 2
    while i >= 0 and A[i] != A[i + 1]:
        i -= 1

    if i < 0:
        return False
    
    for j in reversed(range(i + 2, n - 2)):
        rotate(j)
        rotate(j)
    rotate(i + 1)
    rotate(i)
    
    for j in range(i + 2, n - 2):
        rotate(j)
    
    assert(len(rotations) <= n*n)
    assert(A == sorted(A))
    print len(rotations)
    print ' '.join(str(x + 1) for x in rotations)
    return True

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    if not solve(A):
        print -1