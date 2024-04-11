import sys
range = xrange
input = sys.stdin.readline

n, k = [int(x) for x in input().split()]
k += 1

unique = [1]*n
def check(i):
    if unique[i]:
        print '?', i + 1
        sys.stdout.flush()
        if input()[0] == 'Y':
            unique[i] = 0

def reset():
    print 'R'

def ans():
    print '!', sum(unique)

def solve(A):
    if len(A) <= k:
        for a in A:
            check(a)
        return

    B = []
    while A:
        B.append(A[-(k//2):])
        del A[-(k//2):]
    m = len(B)
    for i in range(m):
        j = i + 1
        while j < m:
            for b in B[j]:
                check(b)
            j += 1
            for b in B[i]:
                check(b)
            if j < m:
                for b in B[j]:
                    check(b)
                j += 1
            reset()

solve(list(range(n)))
ans()