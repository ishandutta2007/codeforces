import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1

    A = []
    while n > 0:
        k = len(A) + 1
        A.append(k)
        n -= k

    if n == 0:
        print len(A)
    else:
        for i in range(len(A)):
            if -n == A[i] + 1:
                print len(A)
                break
        else:
            print len(A) + 1