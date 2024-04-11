import sys, os
range = xrange
input = raw_input
 
numbs = [int(x) for x in sys.stdin.read().split()]
n = numbs.pop(0)
 
base = []
out = []
 
for i in range(n):
    x = numbs[i]
    how = 0
    
    for b,rep in base:
        if x.bit_length() == b.bit_length():
            x ^= b
            how ^= rep
    
    if x:
        how |= 1 << i
 
        a = 0
        b = len(base)
        while a < b:
            c = a + b >> 1
            if base[c][0] > x:
                a = c + 1
            else:
                b = c
        base.insert(a, (x, how))
    
        out.append(0)
    else:
        outind = len(out)
        out.append(-1)
        
        y = bin(how)
        ylen = len(y)
        for i in range(2,len(y)):
            if y[i] == '1':
                out.append(ylen - 1 - i)
        out[outind] = len(out) - 1 - outind
 
os.write(1, '\n'.join(str(x).encode('ascii') for x in out))