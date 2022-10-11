import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

def solve(n, P):
    P.append(0)
    i = 0
    A = []
    while i < n:
        j = i
        while j < n and P[i] + (j - i) == P[j]:
            j += 1
        A.append(P[i])
        i = j
    return A == sorted(A, reverse = True)

t = inp[ii]; ii += 1
ans = []
for _ in range(t):
    n = inp[ii]; ii += 1
    P = inp[ii:ii + n]; ii += n

    if solve(n, P):
        ans.append('Yes')
    else:
        ans.append('No')

print '\n'.join(ans)