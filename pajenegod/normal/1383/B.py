import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n

    xor = 0
    for a in A:
        xor ^= a

    if xor == 0:
        print 'DRAW'
        continue

    high_bit = 1 << xor.bit_length() - 1
    count = 0
    for a in A:
        if a & high_bit:
            count += 1
    print 'WIN' if (count - 1 >> 1) & 1 == 0 or n & 1 == 0 else 'LOSE'