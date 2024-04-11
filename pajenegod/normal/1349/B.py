import sys
range = xrange
input = raw_input

def solve(n,k,A):
    indk = [i for i in range(n) if A[i] == k]
    if not indk:
        return False
    if n == 1:
        return True
    
    for i in range(n - 1):
        if A[i] >= k and A[i + 1] >= k:
            return True
    for i in range(n - 2):
        if A[i] >= k and A[i + 2] >= k:
            return True
    return False
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
out = []
for _ in range(t):
    n = inp[ii]; ii += 1
    k = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n
    
    out.append('yes' if solve(n,k,A) or solve(n,k,A[::-1]) else 'no')
print '\n'.join(out)