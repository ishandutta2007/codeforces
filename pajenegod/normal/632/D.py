import sys
range = xrange
input = raw_input
 
n,m = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
counter = [0]*(m+1)
for a in A:
    if a <= m:
        counter[a] += 1
 
lcm = [0]*(m+1)
for d in range(1,m+1):
    for j in range(d,m+1,d):
        lcm[j] += counter[d]
 
lcm = max(range(1, m+1), key = lcm.__getitem__)
out = []
for i,a in enumerate(A):
    if lcm != 0 and lcm%a == 0:
        out.append(i)
print lcm, len(out)
print ' '.join(str(x+1) for x in out)