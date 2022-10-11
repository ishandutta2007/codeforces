import sys
range = xrange
input = raw_input

MOD = 10**9+7

big = 200010
modinv = [1]*big
for i in range(2,big):
    modinv[i] = int((-(MOD//i)*modinv[MOD%i])%MOD)

fac = [1]
for i in range(1,big):
    fac.append(int(fac[-1]*i%MOD))

invfac = [1]
for i in range(1,big):
    invfac.append(int(invfac[-1]*modinv[i]%MOD))

def choose(n,k):
    return int(fac[n]*invfac[k]*invfac[n-k]%MOD)



count = 0
def add(x,y):
    global count
    count += 1
    return (x + y if count & 1 else x - y)%MOD

def adder2(A):
    n = len(A)
    if n == 1:
        return sum(A)
    global count
    if n%4 == 1:
        return sum(A[i]*choose(n//2, i//2)%MOD for i in range(0,n,2))%MOD
    return adder2([add(A[i], A[i + 1]) for i in range(len(A) - 1)])

n = int(input())
print adder2([int(x) for x in input().split()])