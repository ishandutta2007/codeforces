import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]
ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

if m == 0:
    #print ' '.join(['1']*n)
    print -1
    sys.exit()

coupl = [[] for _ in range(n)]
a = inp[ii] - 1; ii += 1
b = inp[ii] - 1; ii += 1

ii -= 2

for _ in range(m):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    coupl[u].append(v)
    coupl[v].append(u)

A = set(coupl[a])
B = set(coupl[b])

C = A & B
A -= C
B -= C

if len(A) + len(B) + len(C) != n or not A or not B or not C:
    print -1
    sys.exit()

out = [0]*n
for c in range(1, 3 + 1):
    if c == 1:
        D = A
    elif  c == 2:
        D = B
    else:
        D = C

    left = n - len(D)
    for node in D:
        out[node] = c
        if len(coupl[node]) != left or any(nei in D for nei in coupl[node]):
            print -1
            sys.exit()
print ' '.join(str(x) for x in out)