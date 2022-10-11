import sys
input = raw_input

def first_bad(A, k):
    seen = [0] * 10
    for i,a in enumerate(A):
        if seen[a] == 0:
            k -= 1
            seen[a] = 1
        if k < 0:
            return i
    return -1

t = int(input())
for _ in range(t):
    n,k = [int(x) for x in input().split()]

    A = [ord(c) - ord('0') for c in str(n)]
    
    while True:
        i = first_bad(A, k)
        if i == -1:
            break
        A[i] += 1
        while i and A[i] == 10:
            i -= 1
            A[i] += 1
        for j in range(i + 1, len(A)):
            A[j] = 0

    print ''.join(str(x) for x in A)