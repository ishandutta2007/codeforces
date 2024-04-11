import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

out = []
t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n
    for i in range(n):
        A[i] = i - A[i]
    x = 0
    for _ in range(n):
        x = A[x]
    ans = []
    y = A[x]
    while x != y:
        ans.append(y + 1)
        y = A[y]
    ans.append(x + 1)
    out.append(len(ans))
    out += ans
print ' '.join(str(x) for x in out)