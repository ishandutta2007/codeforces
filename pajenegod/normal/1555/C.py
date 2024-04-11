import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    m = int(input())
    A = [int(x) for x in input().split()]
    B = [int(x) for x in input().split()]
    
    cumsumA = [0]
    for a in A:
        cumsumA.append(cumsumA[-1] + a)
    cumsumB = [0]
    for b in B:
        cumsumB.append(cumsumB[-1] + b)
    

    print min(max(cumsumA[m] - cumsumA[i + 1], cumsumB[i] - cumsumB[0]) for i in range(m))