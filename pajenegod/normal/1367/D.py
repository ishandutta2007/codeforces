import sys
range = xrange
input = raw_input

def mapper(S):
    return [ord(c) - ord('a') for c in S]

def remapper(S):
    return ''.join(chr(c + ord('a')) for c in S)

def solve(S, n, B):
    buckets = [0] * 30
    for c in S:
        buckets[c] += 1
    
    T = [-1] * m

    ind = 29
    while any(b == 0 for b in B):
        I = [i for i in range(n) if B[i] == 0]
        while ind >= 0 and buckets[ind] < len(I):
            ind -= 1
        assert ind >= 0
        
        for i in I:
            T[i] = ind
            B[i] = -1
        ind -= 1

        for j in range(n):
            if B[j] > 0:
                for i in I:
                    B[j] -= abs(i - j)
    assert all(ind >= 0 for ind in T)
    assert all(b < 0 for b in B)
    return T

t = int(input())
for _ in range(t):
    S = input()
    m = int(input())
    B = [int(x) for x in input().split()]
    
    print remapper(solve(mapper(S), m, B))