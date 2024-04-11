# Not my code https://codeforces.com/contest/1574/submission/129461481
 
import __pypy__
 
int_add = __pypy__.intop.int_add
int_sub = __pypy__.intop.int_sub
int_mul = __pypy__.intop.int_mul
 
 
def make_mod_mul(mod=10**9 + 7):
    fmod_inv = 1.0 / mod
 
    def mod_mul(a, b, c=0):
        return int_sub(int_add(int_mul(a, b), c), int_mul(mod, int(fmod_inv * a * b + fmod_inv * c))) % MOD
    return mod_mul
 
 
mod_mul = make_mod_mul(mod = 998244353)
 
 
def mod_pow(x, y):
    if y == 0:
        return 1
    res = 1
    while y > 1:
        if y & 1 == 1:
            res = mod_mul(res, x)
        x = mod_mul(x, x)
        y >>= 1
    return mod_mul(res, x)
 
import sys,io,os
try:Z=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
except:Z=lambda:sys.stdin.readline().encode()
sub=lambda x:int(x)-1
Y=lambda:map(sub,Z().split())
from collections import defaultdict as dd
from heapq import *
input=Z
n,m,k = map(int, input().split())
nex = [-1] * k
prev = [-1] * k
bad = [0] * k
 
for _ in range(n):
    l = list(map(int, input().split()))
    nn = l.pop(0)
    tg = 1
    for i in range(nn - 1):
        u, v = l[i] - 1, l[i+1] - 1
        tg = tg and +(prev[v] == -1 or prev[v] == u)
        prev[v] = u
        tg = tg and +(nex[u] == -1 or nex[u] == v)
        nex[u] = v
    if not tg:
        for v in l:
            bad[v - 1] = 1
 
MOD = 998244353
b = 500
ct = [0] * b
ot = []
dp = [1]
 
for i in range(k):
    ib = 0
    curr = i
    val = 0
    if prev[i] == -1:
        while curr != -1:
            ib = ib or bad[curr]
            if ib:
                break
            curr = nex[curr]
            val += 1
        if not ib:
            if val < b:
                ct[val] += 1
            else:
                    ot.append(val)
            
for i in range(1, m + 1):
    curr = 0
    for j in range(1, b):
        if j <= i:
            curr = mod_mul(ct[j], dp[i - j], curr)
    for j in ot:
        if j <= i:
            curr = (curr + dp[i - j]) % MOD
    dp.append(curr)
    
print(dp[m])