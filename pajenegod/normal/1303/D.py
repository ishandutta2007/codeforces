import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0

t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    m = int(inp[ii]); ii += 1

    cost = 0

    A = [int(x) for x in inp[ii: ii + m]]; ii += m
    
    counter = [0]*(65)
    for a in A:
        counter[a.bit_length() - 1] += 1

    for i in range(64):
        val = 1 << i
        c = counter[i]
        
        if c and n & val:
            c -= 1
            n ^= val

        if c and n & (val - 1):
            c -= 1
            cost += i - (n ^ (n - 1)).bit_length() + 1
            n ^= n & (val - 1)

        counter[i + 1] += c >> 1
    
    if n:
        print -1
    else:
        print cost