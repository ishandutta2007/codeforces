import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + 2 * n]; ii += 2 * n
    odds = []
    even = []
    for i in range(2 * n):
        (odds if A[i] & 1 else even).append(i)
    count = n - 1
    while len(odds) >= 2 and count:
        a = odds.pop()
        b = odds.pop()
        out.append(a)
        out.append(b)
        count -= 1
    while len(even) >= 2 and count:
        a = even.pop()
        b = even.pop()
        out.append(a)
        out.append(b)
        count -= 1

print '\n'.join(str(x + 1) for x in out)