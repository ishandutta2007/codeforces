import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0

t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    S = inp[ii]; ii += 1
    S = [0 if c == 'L' else 1 for c in S]
    
    counter = [0] * n

    i = 0
    while i < n:
        par = S[i]
        j = i
        while j < n and S[j] == par:
            par ^= 1
            j += 1
        
        for ind in range(i, j):
            counter[ind] = j - i
        i = j

    ans = [0] * (n + 1)
    for i in range(n + 1):
        if i and S[i - 1] == 0:
            ans[i] = counter[i - 1]
        elif i < n and S[i] == 1:
            ans[i] = counter[i]

    print ' '.join(str(x + 1) for x in ans)