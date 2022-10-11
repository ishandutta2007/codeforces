import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    
    C = [0] * n

    for bit in range(max(A).bit_length()):
        B = [(a >> bit) & 1 for a in A]

        for i in range(1,n):
            if B[i - 1] == 1 and B[i] != 1:
                C[i] += 1 << bit
                B[i] = 1

    print ' '.join(str(x) for x in C)