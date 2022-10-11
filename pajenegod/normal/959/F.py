import sys
range = xrange
input = raw_input

MOD = 10**9 + 7
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
q = inp[ii]; ii += 1

A = inp[ii: ii + n]; ii += n

zeros = [1]
Abase = []
base = []
for i in range(n):
    a = A[i]
    for b in base:
        if a ^ b < a:
            a ^= b
    if a:
        base = list(base)
        base.append(a)
        base.sort(reverse = True)
        zeros.append(zeros[-1])
    else:
        zeros.append(zeros[-1] * 2 % MOD)
    Abase.append(base)

out = []
for _ in range(q):
    l = inp[ii] - 1; ii += 1
    x = inp[ii]; ii += 1

    for b in Abase[l]:
        if x ^ b < x:
            x ^= b

    out.append(0 if x else zeros[l + 1])

print '\n'.join(str(x) for x in out)