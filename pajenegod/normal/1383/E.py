import sys
range = xrange
input = raw_input

MOD = 1000000007
def red(x):
    return x if x < MOD else x - MOD

S = input()
n = len(S)

i = 0
while i < n and S[i] == '0':
    i += 1
if i == n:
    print n
    sys.exit()
j = n
while j and S[j - 1] == '0':
    j -= 1


fac = (i + 1) * (n - j + 1)
S = S[i:j]
n = len(S)

count0 = [+(c == '0') for c in S]
for i in reversed(range(n - 1)):
    if count0[i]:
        count0[i] += count0[i + 1]

ways0 = 1
ways1 = 0

buckets = [0] * (n + 1)
buckets[0] = 1
for i in reversed(range(n)):
    if count0[i]:
        c = count0[i]
        ways0 = red(ways0 - buckets[c] + MOD)
        
        buckets[c] = ways1
        ways0 = red(ways0 + ways1)
    else:
        ways1 = red(ways1 + ways0)

print ways1 * fac % MOD