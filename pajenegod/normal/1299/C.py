import sys, os
 
n = int(sys.stdin.buffer.readline())
A = [int(x) for x in sys.stdin.buffer.readline().split()]
 
cumsum = [0.0]
for a in A:
    cumsum.append(cumsum[-1] + a)
 
def mean(interval):
    i, j = interval
    return (cumsum[j] - cumsum[i]) / (j - i)
 
B = []
for i in range(n):
    B.append((i, i + 1))
    while len(B) > 1 and mean(B[-2]) >= mean(B[-1]):
        _,j = B.pop()
        i,_ = B.pop()
        B.append((i,j))
 
ans = [0.0]*n
for i,j in B:
    x = mean((i,j))
    for k in range(i,j):
        ans[k] = x
os.write(1, b' '.join(repr(x).encode('ascii') for x in ans))