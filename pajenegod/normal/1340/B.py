import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]

numbs = ["1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"]
numbs = [int(x,2) for x in numbs]

counter = [0]*(2**7)
for i in range(1, 2**7):
    counter[i] = 1 + counter[i & (i - 1)]

A = [int(input(),2) for _ in range(n)]

# DP[i][x] 
DP = [[-1]*(k + 1) for _ in range(n + 1)]
digit = [[-1]*(k + 1) for _ in range(n + 1)]
DP[-1][-1] = 0

for i in reversed(range(n)):
    dpi = DP[i]
    dpip1 = DP[i + 1]
    digiti = digit[i]
    for j in range(k + 1):
        for dig in reversed(range(10)):
            if A[i] & ~numbs[dig] == 0:
                jprim = j + counter[A[i] ^ numbs[dig]]
                if jprim <= k and dpip1[jprim] != -1:
                    dpi[j] = jprim
                    digiti[j] = dig
                    break
if DP[0][0] == -1:
    print -1
    sys.exit()
ans = []
j = 0
for i in range(n):
    d = digit[i][j]
    ans.append(d)
    j += counter[A[i] ^ numbs[d]]
print ''.join(str(x) for x in ans)