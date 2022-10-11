import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    input()
    k,n,m = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]
    B = [int(x) for x in input().split()]

    A.reverse()
    B.reverse()

    C = []
    while A or B:
        if not B or (A and A[-1] == 0) or (A and B and A[-1] < B[-1]):
            C.append(A.pop())
        else:
            C.append(B.pop())

    for c in C:
        if c > k:
            break
        k += c == 0
    else:
        print ' '.join(str(c) for c in C)
        continue
    print -1