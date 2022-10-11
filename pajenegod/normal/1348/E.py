import sys
range = xrange
input = raw_input
 
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
 
n = inp[ii]; ii += 1
k = inp[ii]; ii += 1
 
A = inp[ii + 0: ii + 2 * n: 2]
B = inp[ii + 1: ii + 2 * n: 2]
ii += 2 * n
 
reachable = 1
mask = (1 << k) - 1
 
i = 0
while i < n and reachable != mask:
    a = A[i]
    b = B[i]
    
    tmp = reachable 
    if a + b >= k:
        for j in range(max(k - b, 1), min(k,a + 1)):
            tmp |= reachable << j
    reachable |= (tmp & mask) | (tmp >> k)
    i += 1
asum = sum(A)
bsum = sum(B)
x,y = divmod(asum + bsum, k)
 
reachable = [+(c == '1') for c in bin(reachable + (1 << k))[3:]][::-1]
for aused in range(k):
    if reachable[aused]:
        aleft = (asum - aused) % k
        bleft = (bsum + aused) % k
        if aleft + bleft == y:
            print x
            break
else:
    print x - 1