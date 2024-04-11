import sys
range = xrange
input = raw_input

MOD = 998244353 

m,n = [int(x) for x in input().split()]
C = [int(x) - 1 for x in input().split()]

C2 = [C[0]]
for c in C:
    if C2[-1] != c: 
        C2.append(c)
C = C2
n = len(C)

if n > 2*m:
    print 0
    sys.exit()

pos = [[] for _ in range(n)]
for i in range(n):
    pos[C[i]].append(i)


DP = [[1]*(n + 1) for _ in range(n + 1)]
for le in range(1, n + 1):
    for i in range(n - le + 1):
        j = i + le
        k1 = min(range(i,j), key = C.__getitem__)
        c = C[k1]

        k1 = pos[c][0]
        k2 = pos[c][-1]

        ans1 = 0
        for split in range(i,k1 + 1):
            ans1 += DP[i][split] * DP[split][k1] % MOD   
        
        ans2 = 0
        for split in range(k2+1, j + 1):
            ans2 += DP[k2 + 1][split] * DP[split][j] % MOD

        posc = pos[c]
        for ind in range(len(posc) - 1):
            ans1 = (ans1 * DP[posc[ind] + 1][posc[ind + 1]] % MOD)

        DP[i][j] = int((ans1 % MOD) * (ans2 % MOD) % MOD)

print DP[0][n]