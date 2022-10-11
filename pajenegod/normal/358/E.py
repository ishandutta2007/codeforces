import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]

A = []
for _ in range(n):
    A.append([int(x) for x in input().split()])

Arowsum = []
for a in A:
    cumsum = [0]
    for j in range(m):
        cumsum.append(cumsum[-1] + a[j])
    Arowsum.append(cumsum)
Acolsum = []
for j in range(m):
    cumsum = [0]
    for i in range(n):
        cumsum.append(cumsum[-1] + A[i][j])
    Acolsum.append(cumsum)

rowcount = [0] * n
colcount = [0] * m
for i in range(n):
    rowcount[i] = Arowsum[i][-1]

for j in range(m):
    colcount[j] = Acolsum[j][-1]
Asum = sum(rowcount)

# Somehow the answer for Asum = 1 is -1
if Asum == 1:
    print -1
    sys.exit()

Y = 0
while not rowcount[Y]:
    Y += 1
X = 0
while not colcount[X]:
    X += 1

def check(d):
    x = X % d
    y = Y % d
    
    N = (n - y + d - 1) // d
    M = (m - x + d - 1) // d
    for i in range(N):
        for j in range(M):
            if A[d * i + y][d * j + x]:
                break
        else:
            continue
        break
    else:
        return False

    found = [[0] * M for _ in range(N)]
    odd_deg = 0
    count = 0
    bfs = [(i,j)]
    for i,j in bfs:
        if found[i][j]:
            continue
        deg = 0
        
        truei = d * i + y
        truej = d * j + x
        
        found[i][j] = 1
        count += 1
        
        i2 = i + 1
        j2 = j
        truei2 = truei + d
        colsum = Acolsum[truej]

        if i2 < N and colsum[truei2 + 1] - colsum[truei] == d + 1:
            deg += 1
            bfs.append((i2,j2))
        
        i2 = i - 1
        j2 = j
        truei2 = truei - d
        colsum = Acolsum[truej]

        if 0 <= i2 and colsum[truei + 1] - colsum[truei2] == d + 1:
            deg += 1
            bfs.append((i2,j2))
        
        i2 = i
        j2 = j + 1
        truej2 = truej + d
        rowsum = Arowsum[truei]

        if j2 < M and rowsum[truej2 + 1] - rowsum[truej] == d + 1:
            deg += 1
            bfs.append((i2,j2))
        
        i2 = i
        j2 = j - 1
        truej2 = truej - d
        rowsum = Arowsum[truei]

        if 0 <= j2 and rowsum[truej + 1] - rowsum[truej2] == d + 1:
            deg += 1
            bfs.append((i2,j2))

        odd_deg += deg & 1
    
    edges = len(bfs) // 2
    nodes = sum(sum(f) for f in found)
    found_ones = nodes + edges * (d - 1)
    return found_ones == Asum and odd_deg <= 2


ans = []
for d in range(2, min(n, m) + 1):
    if check(d):
        ans.append(d)

print ' '.join(str(x) for x in (ans if ans else [-1]))