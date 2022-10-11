import sys
range = xrange
input = raw_input

def LPSubstr(s):
    n = len(s)
    p = [[0] * (n + 1), [0] * n]

    for z, p_z in enumerate(p):
        left, right = 0, 0
        for i in range(n):
            t = right - i + 1 - z
            if i < right:
                p_z[i] = min(t, p_z[left + t])
            L, R = i - p_z[i], i + p_z[i] - 1 + z
            while (L >= 1) and (R + 1 < n) and (s[L - 1] == s[R + 1]):
                p_z[i] += 1
                L -= 1
                R += 1
            if R > right:
                left, right = L, R

    return p[0], p[1]

def solve(S):
    n = len(S) 
    p0, p1 = LPSubstr(S)
    
    reach = list(range(n))
    for i in range(n):
        x = i - p0[i]
        y = i + p0[i] - 1
        if x <= n - 1 - y:
            reach[x] = max(reach[x], y)
        x = i - p1[i]
        y = i + p1[i]
        if x <= n - 1 - y:
            reach[x] = max(reach[x], y)
    
    for i in range(n - 1):
        reach[i + 1] = max(reach[i] - 1, reach[i + 1])

    besta = -1
    bestai = -1
    bestareach = -1

    i = -1
    j = n
    while i < j:
        cand = i + 2 + reach[i + 1]
        if cand > besta:
            besta = cand
            bestai = i + 1
            bestareach = reach[i + 1]

        i += 1
        j -= 1
        if S[i] != S[j]:
            break
    return S[:bestareach + 1] + S[n - bestai:]


orda = ord('a')
inf = 10**9

inp = sys.stdin.read().split(); ii = 0

t = int(inp[ii]); ii += 1
out = []
for _ in range(t):
    S = [ord(c) - orda for c in inp[ii]]; ii += 1
    if S == S[::-1]:
        out.append(S)
    else:
        S1 = solve(S)
        S2 = solve(S[::-1])[::-1]
        out.append(S1 if len(S1) > len(S2) else S2)

print '\n'.join(''.join(chr(c + orda) for c in S) for S in out)