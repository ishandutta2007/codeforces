import sys
range = xrange
input = raw_input

def solve(n):
    if n % 4 != 0:
        return False, []
    m = n//2

    odd = []
    i = 1
    while len(odd) < m:
        odd.append(i)
        i += 2

    even = []
    i = 2
    while len(even) < m:
        even.append(i)
        i += 2

    odd[-1] += sum(even) - sum(odd)
    return True, even + odd

t = int(input())
for _ in range(t):
    n = int(input())
    exists, A = solve(n)
    if exists:
        print 'YES'
        print ' '.join(str(x) for x in A)
    else:
        print 'NO'