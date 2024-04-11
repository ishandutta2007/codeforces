import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

A = [_ - 1 for _ in inp[ii: ii + n]]; ii += n

towers = [set() for _ in range(m)]
cost = 0
for i in reversed(range(n)):
    tow = towers[A[i]]

    if i < n - 1 and i + 1 not in tow:
        cost += 1
    tow.add(i)

out = [cost]
for _ in range(m - 1):
    a = inp[ii] - 1; ii += 1
    b = inp[ii] - 1; ii += 1

    T1,T2 = towers[a],towers[b]
    if len(T1) >= len(T2):
        T1,T2 = T2,T1
    
    for i in T1:
        cost -= i + 1 not in T1 and i + 1 in T2
        cost -= i - 1 in T2
    
    T2 |= T1
    out.append(cost)
    towers[a] = towers[b] = T2

print '\n'.join(str(x) for x in out)