import sys

inp = sys.stdin.read().split(); ii = 0

t = int(inp[ii]); ii += 1
for _ in range(t):
    S = inp[ii]; ii += 1
    n = len(S)

    previous = [-1] * 100
    
    DP = [-1] * (n + 1)
    DP[-1] = 0

    for i in reversed(range(n)):
        c = ord(S[i]) - ord('a')
        
        alt = 1 + DP[i + 1]
        j = previous[c]
        if j != -1:
            alt = min(alt, j - i - 1 + DP[j + 1])
        DP[i] = alt
        previous[c] = i
    print DP[0]