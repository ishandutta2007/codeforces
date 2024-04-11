import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0

t = int(inp[ii]); ii += 1
for _ in range(t):
    S = [+(c=='R') for c in inp[ii]]; ii += 1
    n = len(S)
    best = 1

    i = 0
    while i < n:
        while i < n and S[i]:
            i += 1
        j = i
        while j < n and S[j] == 0:
            j += 1 
        best = max(best, j - i + 1)
        i = j
    print best