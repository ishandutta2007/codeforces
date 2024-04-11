import sys
range = xrange
input = raw_input

n = int(input())

B = [int(x) for x in sys.stdin.readline().split()]

Abeg = []
Aend = []
for b in B:
    if Abeg:
        smallest = Abeg[-1]
    else:
        smallest = 0
    if Aend:
        biggest = Aend[-1]
    else:
        biggest = 10**18
    
    val = min(b,biggest)
    
    if b-val<smallest:
        val = b-smallest
    Abeg.append(b-val)
    Aend.append(val)

Aend.reverse()
A = Abeg + Aend

print ' '.join(str(x) for x in A)