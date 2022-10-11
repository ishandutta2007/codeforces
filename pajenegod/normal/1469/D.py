import sys
range = xrange
input = raw_input

def f(a,b):
    a = (a + b - 1) // b
    a = (a + b - 1) // b
    return a

def g(a,b):
    return (a + b - 1) // b

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = [i for i in range(n + 1)]

    tmp = []
    j = n
    while n > 2:
        while j > 2 and f(n, j - 1) == 1:
            j -= 1
        
        for i in range(j + 1, n):
            A[i] = g(A[i], A[n])
            tmp.append('%d %d' % (i, n))
        
        A[n] = g(A[n], A[j])
        A[n] = g(A[n], A[j])
        tmp.append('%d %d' % (n,j))
        tmp.append('%d %d' % (n,j))
        n = j

    out.append(str(len(tmp)))
    out += tmp
    #print A[1:]

print '\n'.join(out)