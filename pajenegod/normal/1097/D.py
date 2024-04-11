import sys
range = xrange
input = raw_input

MOD = 10**9 + 7

n,k = [int(x) for x in input().split()]

big = 200
MODI = [0]*big
for i in range(1,big):
    MODI[i] = pow(i,MOD-2,MOD)

# This is a multiplicative property
EXP = 1

i = 2
while n>1 and i*i<=n:
    if n%i==0:
        count = 0
        while n%i==0:
            n//=i
            count += 1
        
        arr = [0]*(count+1)
        arr[-1] = 1

        for _ in range(k):
            val = 0
            for j in reversed(range(count+1)):
                val = (val + arr[j]*MODI[j+1])%MOD
                arr[j] = val
        tmp = 0
        for j in range(count+1):
            tmp += (i**j)*arr[j]
        EXP = EXP*tmp%MOD

    i += 1

if n>1:
    i=n
    count = 0
    while n%i==0:
        n//=i
        count += 1
    
    arr = [0]*(count+1)
    arr[1] = 1

    for _ in range(k):
        val = 0
        for j in reversed(range(count+1)):
            val = (val + arr[j]*MODI[j+1])%MOD
            arr[j] = val
    tmp = 0
    for j in range(count+1):
        tmp += (i**j)*arr[j]
    EXP = EXP*tmp%MOD

print EXP%MOD