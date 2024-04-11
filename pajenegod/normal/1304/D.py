import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0

t = int(inp[ii]); ii += 1
out = []
for _ in range(t):
    n = int(inp[ii]); ii += 1
    S = inp[ii]; ii += 1

    m = S.count('<')
    
    i = n - m
    j = n - m - 1
    
    longest = [i]
    i += 1
    for c in S:
        if c == '<':
            longest.append(i)
            i += 1
        else:
            longest.append(j)
            j -= 1

    
    shortest = []
    a = n - m - (S[0] == '<') + 1
    b = a - 1
    a = n
    i = 0
    
    while i < n - 1:
        j = i + 1
        while j < n - 1 and S[i] == S[j]:
            j += 1

        if S[i] == '<':
            l = j - i + (i == 0)
            shortest += range(a - l + 1, a + 1)
            a -= l
        else:
            l = j - i + (i == 0)
            shortest += reversed(range(b - l + 1, b + 1))
            b -= l
        i = j

    out.append(' '.join(str(x) for x in shortest))
    out.append(' '.join(str(x) for x in longest))
print '\n'.join(out)