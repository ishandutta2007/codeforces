import sys
range = xrange
input = raw_input

big = 100010
P = [True]*big
P[0] = P[1] = False
for i in range(big):
    if P[i]:
        j = i*i
        if j>=big: break
        while j<big:
            P[j] = False
            j += i

P = [p for p in range(big) if P[p]]

mu = [1]*big
for p in P:
    j = p
    while j < big:
        mu[j] = -mu[j]
        j += p


for p in P:
    i = p*p
    if i>=big: break
    
    j = i
    while j<big:
        mu[j] = 0
        j += i


MOD = 10**9 + 7

div = [0]*big

n = int(input())
A = [int(x) for x in input().split()]
for a in A:
    i = 1
    while i*i<a:
        if a%i==0:
            div[i] += 1
            div[a//i] += 1
        i += 1
    if i*i==a:
        div[i] += 1

ans = 0
for i in range(big):
    ans = (ans + mu[i]*(pow(2,div[i],MOD) - 1))%MOD

print ans