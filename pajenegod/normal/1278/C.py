import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    
    A = inp[ii:ii + n]; ii += n
    B = inp[ii:ii + n][::-1]; ii += n

    count = 0
    found = {0:-1}
    for i in range(n):
        if A[i] == 1:
            count += 1
        else:
            count -= 1
        found[count] = i

    

    best = found[0] + 1
    count = 0
    for i in range(n):
        if B[i] == 1:
            count += 1
        else:
            count -= 1
        if -count in found:
            j = found[-count]
            cand = i + j + 2
            if cand > best:
                best = cand

    print 2 * n - best