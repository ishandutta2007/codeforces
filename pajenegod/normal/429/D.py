import os,math
range = xrange
cumsum = [int(x) for x in os.read(0,os.fstat(0).st_size).split()]
n = cumsum[0]
cumsum[0] = 0
for i in range(n):
    cumsum[i+1] += cumsum[i]

def work(besta, i, sqrtbesta, lowerbound, upperbound, cumsumi):
    for j in range(i+1, min(n, i - 1 + sqrtbesta) + 1):
        if lowerbound < cumsum[j] < upperbound and (j-i)**2 + (cumsum[j] - cumsumi)**2 < besta:
            besta = (j-i)**2 + (cumsum[j] - cumsumi)**2
    return besta

besta = 10100**2
for i in range(1,n):
    sqrtbesta = int(math.sqrt(besta)) + 1
    lowerbound = -sqrtbesta + cumsum[i]
    upperbound = sqrtbesta + cumsum[i]
    besta = work(besta, i, sqrtbesta, lowerbound, upperbound, cumsum[i])
print(besta)