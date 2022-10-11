import sys
range = xrange
input = raw_input

t = int(input())

def solve(n,A,B):
    for i in range(n):
        if A[i] > B[i]:
            return -1
    
    buckets = [[] for _ in range(25)]
    for i in range(n):
        if A[i] != B[i]:
            buckets[A[i]].append(i)
    
    moves = 0
    while A != B:
        for b in buckets:
            if b: break
        
        nesta = min(B[i] for i in b)
        moves += 1
        for i in b:
            A[i] = nesta
        buckets[nesta] += (i for i in b if A[i] != B[i])
        del b[:]
    return moves

def mapper(A):
    return [ord(c) - ord('a') for c in A]

for _ in range(t):
    n = int(input())
    A = input()
    B = input()
        
    print solve(n, mapper(A), mapper(B))