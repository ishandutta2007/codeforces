import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    B = [int(x) for x in input().split()]

    count = [0]*3
    for a in A:
        count[a] += 1

    for i in reversed(range(n)):
        count[A[i]] -= 1

        if B[i] == A[i]:
            pass
        elif B[i] > A[i]:
            if not count[1]:
                break
        elif B[i] < A[i]:
            if not count[-1]:
                break
    else:
        print 'YES'
        continue
    print 'NO'