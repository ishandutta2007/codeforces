import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    m = inp[ii]; ii += 1
    mat = inp[ii: ii + n * m]; ii += n * m

    A = []
    for i in range(n):
        A.append(mat[i * m: (i + 1) * m])


    s = 0

    nhalf = n + 1 >> 1
    mhalf = m + 1 >> 1



    for i in range(nhalf):
        for j in range(mhalf):
            x = sorted([A[i][j],A[~i][j],A[i][~j],A[~i][~j]])[1]
            y = abs(A[i][j] - x)  + \
                abs(A[~i][j] - x) + \
                abs(A[i][~j] - x) + \
                abs(A[~i][~j] - x)
            f = 2**((2 * i == n - 1) + (2 * j == m - 1))
            s += y // f
    print s