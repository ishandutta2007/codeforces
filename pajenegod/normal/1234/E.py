import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]
X = [int(x) - 1 for x in input().split()]

s = 0
rightcount = [0]*n
leftcount = [0]*n
leftsum = [0]*n
for j in range(m - 1):
    a,b = (X[j], X[j + 1]) if X[j] < X[j + 1] else (X[j + 1], X[j])
    if a == b:
        continue
    rightcount[a] += 1
    leftcount[b] += 1
    leftsum[b] += a
    s += b - a

diff1 = [leftcount[i] - leftcount[i - 1] for i in range(1, n)]
diff2 = [leftsum[i] - leftsum[i - 1] for i in range(1, n)]
diff3 = [rightcount[i] - rightcount[i - 1] for i in range(1, n)]


out = [s]
for i in range(n - 1): 
    s += (1 - i) * diff1[i] + 2 * diff2[i] + (i + 1) * diff3[i]
    out.append(s)
print ' '.join(str(x) for x in out)