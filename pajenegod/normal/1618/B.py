import sys
range = xrange
input = raw_input

def check(A):
    for i in range(len(A) - 1):
        if A[i][1] != A[i + 1][0]:
            return i + 1
    return 0

t = int(input())
for _ in range(t):
    n = int(input())
    A = input().split()

    bad_i = check(A)

    for s in 'aa','ab','bb','ba':
        for ind in bad_i, n:
            B = A[:]
            B.insert(ind, s)

            if not check(B):
                print ''.join(c[0] for c in B) + B[-1][1]
                break
        else:
            continue
        break