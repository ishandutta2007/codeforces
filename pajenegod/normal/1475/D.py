import sys
range = xrange
input = raw_input



inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    m = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n
    B = inp[ii: ii + n]; ii += n

    order = sorted(range(n), key = lambda i: 2 * A[i] // B[i])
    cost = 0

    stack = []
    while order and m > 0:
        m -= A[order[-1]]
        cost += B[order[-1]]
        stack.append(order.pop())

    besta = 0

    if stack:
        lasta = A[stack[-1]]
        lastb = B[stack[-1]]
        
        for i in order:
            if m + lasta - A[i] <= 0 and B[i] < lastb:
                besta = max(besta, lastb - B[i])
        
        if len(stack) > 1:
            lasta += A[stack[-2]]
            lastb += B[stack[-2]]

            for i in order:
                if m + lasta - A[i] <= 0 and B[i] < lastb:
                    besta = max(besta, lastb - B[i])

    for i in stack:
        if m + A[i] <= 0:
            besta = max(besta, B[i])
                
    print cost - besta if m <= 0 else -1