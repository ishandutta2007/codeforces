import sys
range = xrange
input = raw_input

def partial(s):
    g, pi = 0, [0] * len(s)
    for i in range(1, len(s)):
        while g and (s[g] != s[i]):
            g = pi[g - 1]
        pi[i] = g = g + (s[g] == s[i])

    return pi

A = input()
B = input()
C = input()

A = [ord(c) - 97 if c != '*' else -1 for c in A]
B = [ord(c) - 97 for c in B]
C = [ord(c) - 97 for c in C]

n = len(A)
BB = partial(B)
CC = partial(C)
m = len(B)
k = len(C)

inf = 10**9
DP = [[[-inf]*(k + 1) for i in range(m + 1)] for i in range(n + 1)]
DP[0][0][0] = 0
for i in range(1, n + 1):
    DPi = DP[i]
    DPim1 = DP[i - 1]
    for c in (range(0, 26) if A[i - 1] < 0 else (A[i - 1],)):
        for a in range(m + 1):
            newa = a
            if newa == m:
                newa = BB[newa - 1]
            while newa and B[newa] != c:
                newa = BB[newa - 1]
            newa += B[newa] == c
            
            DPinewa = DPi[newa]
            DPim1a = DPim1[a]
            for b in range(k + 1):
                newb = b
                if newb == k:
                    newb = CC[newb - 1]
                while newb and C[newb] != c:
                    newb = CC[newb - 1]
                newb += C[newb] == c
                
                DPinewa[newb] = max(DPinewa[newb],  DPim1a[b] + (newa == m) - (newb == k))
print max([max(d) for d in DP[n]])