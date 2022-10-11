import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split()
ii = 0

q = int(inp[ii])
ii += 1

out = []

for _ in range(q):
    a = int(inp[ii])
    ii += 1
    b = int(inp[ii])
    ii += 1
    S = inp[ii]
    ii += 1
    i = 0
    counter = []
    while i < len(S):
        while i < len(S) and S[i] == 'X':
            i += 1
        if i == len(S):
            break
        j = i
        while j < len(S) and S[j] == '.':
            j += 1

        counter.append(j - i)
        i = j
    
    counter = [l for l in counter if l >= b]
    
    if not counter or any(l < a for l in counter):
        out.append(0)
        continue
    
    counter2 = [l for l in counter if l >= 2 * b]
    counter = [l for l in counter if l < 2 * b]

    if len(counter2)>1:
        out.append(0)
    elif counter2:
        c = counter2[0]
        par = len(counter)&1
        if not par and c - a < 2 * b - 1:
            out.append(1)
        elif not par and a < 2 * b and c - 2*a >= a and c - 2*(2*b - 1) <= a:
            out.append(1)
        elif par and a < 2 * b and c - a >= a and c - (2 * b - 1) - a < b:
            out.append(1)
        else:
            out.append(0)
    else:
        out.append(len(counter)&1)

print '\n'.join('YES' if o else 'NO' for o in out)