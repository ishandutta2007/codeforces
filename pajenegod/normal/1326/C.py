import sys
range = xrange
input = raw_input

MOD = 998244353
n,k = [int(x) for x in input().split()]
P = [int(x) for x in input().split()]

A = []
s = 0
for p in P:
    if p > n - k:
        s += p
        A.append(1)
    else:
        A.append(0)

while A and not A[-1]:
    A.pop()
n = len(A)

i = 0
while i < n and not A[i]:
    i += 1

prod = 1
while i < n:
    j = i + 1
    while j < n and not A[j]:
        j += 1
    prod = prod * (j - i) % MOD
    i = j
    
print s, prod