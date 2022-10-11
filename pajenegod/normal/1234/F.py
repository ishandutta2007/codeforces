import sys
range = xrange
input = raw_input

orda = ord('a')
S = [ord(c) - orda for c in input()]
n = len(S)

best = -1
count = [0]*(2**20)
for i in range(n):
    c = 0
    j = i
    while j < n and c & (1 << S[j]) == 0:
        c ^= 1 << S[j]
        count[c] = 1
        j += 1

big = 2**20
bitsize = [0]
for i in range(1, big):
    bitsize.append(1 +  bitsize[i - (1 <<( i.bit_length() - 1))])

for i in range(big):
    if count[i] == 0:
        bitsize[i] = 0

DP = [0]*big
for i in reversed(range(big)):
    ii = (big - 1) ^ i
    besta = bitsize[ii]
    
    while ii:
        b = ii & (~ii + 1)
        if DP[i ^ b] > besta:
            besta = DP[i ^ b]
        ii ^= b
    DP[i] = besta

print max(DP[i] + bitsize[i] for i in range(big))