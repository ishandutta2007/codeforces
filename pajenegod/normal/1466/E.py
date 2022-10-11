import sys, os
range = xrange
input = raw_input
 
MOD = 10**9 + 7
import __pypy__
mulmod = __pypy__.intop.int_mulmod
 
def solve(n, Asmall, Alarge, An):
    bitcount = [0] * 60
    for i in range(30):
        count = 0
        for x in Asmall:
            count += (x >> i) & 1
        bitcount[i] = mulmod(count, pow(2, i, MOD), MOD)
        
        count = 0
        for x in Alarge:
            count += (x >> i) & 1
        bitcount[i + 30] = mulmod(count, pow(2, i + 30, MOD), MOD)
    
    allsum = int(sum(bitcount) % MOD)
 
    ans = 0
    for ind in range(n):
        sum1 = 0
        xjsmall = Asmall[ind]
        for i in range(30):
            sum1 = (sum1 + bitcount[i]     ) % MOD if (xjsmall >> i) & 1 else sum1
        xjlarge = Alarge[ind]
        for i in range(30):
            sum1 = (sum1 + bitcount[i + 30]) % MOD if (xjlarge >> i) & 1 else sum1
        sum2 = allsum + An[ind]
        ans += sum1 * (sum2 - sum1)
    out.append(ans % MOD)
 
 
inp = os.read(0, os.fstat(0).st_size).split(); ii = 0
out = []
 
t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    
    mask = 2**30 - 1
    Asmall = []
    Alarge = []
    An = []
    for _ in range(n):
        a = int(inp[ii]); ii += 1
        Asmall.append(int(a & mask))
        Alarge.append(int(a >> 30))
        An.append(int(a * n % MOD))
    solve(n, Asmall, Alarge, An)
 
print '\n'.join(str(x) for x in out)