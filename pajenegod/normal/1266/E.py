import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1

A = inp[ii: ii + n]; ii += n
pointed = [0]*n

pointer = {}

ans = []

summa = sum(A)

q = inp[ii]; ii += 1
for _ in range(q):
    s = inp[ii] - 1; ii += 1
    t = inp[ii]; ii += 1
    u = inp[ii] - 1; ii += 1

    if (s,t) in pointer:
        oldu = pointer.pop((s,t))
        if pointed[oldu] <= A[oldu]:
            summa += 1
        pointed[oldu] -= 1
    if u >= 0:
        pointer[s,t] = u
        pointed[u] += 1
        if pointed[u] <= A[u]:
            summa -= 1

    ans.append(summa)
print '\n'.join(str(x) for x in ans)