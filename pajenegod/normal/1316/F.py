import sys, os
range = xrange
input = raw_input
 
import __pypy__
mulmod = __pypy__.intop.int_mulmod
sub = __pypy__.intop.int_sub
mul = __pypy__.intop.int_mul
MOD = 10**9 + 7
MODINV = 1.0/MOD
 
def mulmod(a,b):
    x = sub(mul(a,b), mul(MOD, int(a * MODINV * b)))
    return x + MOD if (x < 0) else (x if x < MOD else x - MOD)
 
 
#precalc 2^-1 powers
invpow = pow(2, MOD - 2, MOD)
pow2 = [1]
for _ in range(3 * 10**5 + 10):
    pow2.append(mulmod(pow2[-1], invpow))
 
# returns order such that A[order[i]] <= A[order[i + 1]]
def sqrtsorted(A, maxval = 10**9):
    asqrt = int((maxval)**0.5 + 2)
    blocks1 = [[] for _ in range(asqrt)]
    blocks2 = [[] for _ in range(asqrt)]
    for i in range(len(A)):
        blocks1[A[i] % asqrt].append(i)
    for block in blocks1:
        for i in block:
            blocks2[A[i]//asqrt].append(i)
    ret = []
    for block in blocks2:
        ret += block
    return ret
 
# Keeps track of expected power using the structure of the segment tree
class segtree:
    def __init__(self, data, counter):
        n = len(data)
        m = 1
        while m < n: m *= 2
        
        self.m = m
        self.dataL = [0]*(m+m)
        self.dataR = [0]*(m+m)
        self.counter = [0]*(m+m)
        self.power = 0
 
        self.dataL[m:m+n] = data
        self.dataR[m:m+n] = data
        self.counter[m:m+n] = counter
 
        for ind in reversed(range(1,m)):
            self.counter[ind] = self.counter[ind << 1] + self.counter[(ind << 1) + 1]
            
            self.dataL[ind] = (mulmod(self.dataL[ind << 1], pow2[self.counter[(ind << 1) + 1]]) + self.dataL[(ind << 1) + 1] ) % MOD
            self.dataR[ind] = (self.dataR[ind << 1] + mulmod(self.dataR[(ind << 1) + 1], pow2[self.counter[ind << 1]]) ) % MOD
            self.power = (self.power + mulmod(self.dataL[ind << 1], self.dataR[(ind << 1) + 1]) ) % MOD
            
 
    
    # Keeps track of expected power when the segment tree is modified
    def add(self, ind, val, c = 1):
        ind += self.m
        while ind > 1:
            self.counter[ind] += c
            self.power = self.power - mulmod(self.dataL[ind & ~1], self.dataR[ind | 1])
            
            # If first time
            if ind >= self.m:
                self.dataL[ind] = val
                self.dataR[ind] = val
            else:
                self.dataL[ind] = (mulmod(self.dataL[ind << 1], pow2[self.counter[(ind << 1) + 1]]) + self.dataL[(ind << 1) + 1] ) % MOD
                self.dataR[ind] = (self.dataR[ind << 1] + mulmod(self.dataR[(ind << 1) + 1], pow2[self.counter[ind << 1]]) ) % MOD
            
            self.power = (self.power + mulmod(self.dataL[ind & ~1], self.dataR[ind | 1]) ) % MOD
            
            ind >>= 1
    
    def rem(self, ind):
        self.add(ind, 0, -1)
    
    def get_power(self):
        return mulmod(self.power, pow2[2])
 
#############
### READ INPUT
 
inp = [int(x) for x in os.read(0, os.fstat(0).st_size).split()]; ii = 0
n = inp[ii]; ii += 1
 
# Order all involved powers
values = inp[ii: ii + n] + inp[ii + n + 2:: 2]
order = sqrtsorted(values)
 
invorder = [-1]*len(order)
for i in range(len(order)):
    invorder[order[i]] = i
 
# Initialize the seg tree containing powers
P = inp[ii: ii + n]; ii += n
who = list(range(n))
 
 
##############
### POPULATE SEGTREE
 
power = 0
 
data = [0]*len(order)
counter = [0]*len(order)
for i in range(n):
    data[invorder[i]] = P[i]
    counter[invorder[i]] = 1
 
seg = segtree(data, counter)
 
##############
### SOLVE QUERIES
 
import __pypy__
out = __pypy__.builders.StringBuilder()
 
q = inp[ii]; ii += 1
out.append(str(seg.get_power()))
out.append('\n')
for _ in range(q):
    i = inp[ii] - 1; ii += 1
    x = inp[ii]; ii += 1
 
    # Remove power at who[i]
    ind = invorder[who[i]]
    seg.rem(ind)
 
    # Add new power at i
    ind = invorder[n + _]
    who[i] = n + _
    seg.add(ind, x)
 
    out.append(str(seg.get_power()))
    out.append('\n')
 
os.write(1, out.build())