import sys
range = xrange
input = raw_input

MOD = 10**9 + 7

big = 2 * 10**5 + 100
DP = [[-1] * 10 for _ in range(big)]

DP[0] = [1] * 10
for i in range(1, big):
    DPi = DP[i]
    DPim1 = DP[i - 1]

    DPi[0] = DPim1[1]
    DPi[1] = DPim1[2]
    DPi[2] = DPim1[3]
    DPi[3] = DPim1[4]
    DPi[4] = DPim1[5]
    DPi[5] = DPim1[6]
    DPi[6] = DPim1[7]
    DPi[7] = DPim1[8]
    DPi[8] = DPim1[9]
    DPi[9] = (DPim1[1] + DPim1[0]) % MOD


inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    m = inp[ii]; ii += 1

    ans = sum(DP[m][int(c)] for c in str(n)) % MOD
    out.append(ans)

print '\n'.join(str(x) for x in out)