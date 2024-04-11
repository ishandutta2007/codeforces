import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

def gcd(a,b):
    while a:
        a,b = b%a,a
    return b

n = inp[ii]; ii += 1

out = []
for i in range(n):
    a = inp[ii]; ii += 1
    b = inp[ii]; ii += 1
    out.append(+(gcd(a,b)==1))

print '\n'.join('Infinite' if not o else 'Finite' for o in out)