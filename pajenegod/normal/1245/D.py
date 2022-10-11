import sys
range = xrange
input = raw_input

def mst(mat):
    n = len(mat)
    root = 0
    found = [0]*n
    found[root] = 1
    vec = list(mat[root])
    who = [root]*n
    pairs = []
    I = 0
    for _ in range(n - 1):
        while found[I]: I += 1
        i = k = I
        minval = vec[I]
        while k < n:
            if not found[k] and vec[k] < minval:
                minval = vec[k]
                i = k
            k += 1
        pairs.append((who[i], i))
        found[i] = 1
        vec2 = mat[i]
        for j in range(n):
            if vec2[j] < vec[j]:
                vec[j] = vec2[j]
                who[j] = i
    return pairs


inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1

X = inp[ii:ii + 2*n: 2]
Y = inp[ii + 1: ii + 2*n: 2]
ii += 2 * n

C = [float(c) for c in inp[ii:ii + n]]; ii += n
K = [float(c) for c in inp[ii:ii + n]]; ii += n

mat = [[0.0]*(n + 1) for _ in range(n + 1)]
for a in range(n):
    for b in range(a + 1, n):
        val = (K[a] + K[b]) * (abs(X[a] - X[b]) + abs(Y[a] - Y[b]))
        mat[a][b] = mat[b][a] = val

for i in range(n):
    mat[i][n] = mat[n][i] = C[i]

cost = 0
power = []
pairs = []
for i,j in mst(mat):
    if i > j:
        i,j = j,i
    cost += mat[i][j]
    if j == n:
        power.append(i)
    else:
        pairs.append((i,j))

print int(cost)
print len(power)
print ' '.join(str(x + 1) for x in power)
print len(pairs)
print '\n' .join('%d %d' % (a+1,b+1) for a,b in pairs)