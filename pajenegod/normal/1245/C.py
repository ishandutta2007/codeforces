import sys
range = xrange
input = raw_input

MOD = 10**9 + 7
big = 100010
DP = [0]*big
DP[0] = 1
DP[1] = 1
for i in range(2, big):
    DP[i] = (DP[i - 2] + DP[i - 1]) % MOD

S = input()
n = len(S)

groups = [0]*big

i = 0
while i < n:
    if S[i] != 'u' and S[i] != 'n':
        i += 1
        continue
    
    j = i + 1
    while j < n and S[i] == S[j]:
        j += 1
    groups[j - i] += 1
    i = j

ways = 1
for i in range(big):
    ways = ways * pow(DP[i], groups[i], MOD) % MOD

if 'm' not in S and 'w' not in S:
    print ways
else:
    print 0