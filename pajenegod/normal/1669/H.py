import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n,k = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]
    
    for bit in reversed(range(31)):
        count = 0
        for a in A:
            count += 1 ^ (1 & (a >> bit))
        if count <= k:
            k -= count
            A = [a | (1 << bit) for a in A]

    Aand = A[0]
    for a in A:
        Aand &= a
    print(Aand)