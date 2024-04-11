import sys, os

#
# Benchmarking weird pypy3
inp = [int(x) for x in os.read(0, 10**7).split()]; ii = 0
 
out = []
 
t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    m = inp[ii]; ii += 1
    A = inp[ii: ii + n * m]; ii += n * m
 
    def solve(bound):
        B = [+(a >= bound) for a in A]
        
        for j in range(m):
            Bcol = [B[ind] for ind in range(j,n*m,m)]
        
            if not any(Bcol):
                return False
 
        for i in range(n):
            Brow = [B[ind] for ind in range(i * m, i * m + m)]
 
            if sum(Brow) >= 2:
                return True
        return False
 
    l = 1
    r = 10**9
    while l < r:
        mid = l + r + 1 >> 1
        if not solve(mid):
            r = mid - 1
        else:
            l = mid
    
    print(l)