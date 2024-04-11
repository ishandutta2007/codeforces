import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
q = inp[ii]; ii += 1

summa = 0.0
diff = 0
par = 0

for _ in range(q):
    if inp[ii] == 1:
        x = inp[ii + 1]; ii += 2
        summa += x
        par ^= x & 1
    else:
        ii += 1
        diff += 1 - 2 * par
        par ^= 1

summa = int(int(summa) % n)
add0 = (summa + diff) % n
add1 = (summa - diff) % n

ans = [0]*n
for x in range(n):
    ans[(x + (add1 if x&1 else add0)) - n] = x + 1
print ' '.join(str(x) for x in ans)