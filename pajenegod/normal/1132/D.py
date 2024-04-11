import sys
import os
from math import trunc

s = os.read(0,os.fstat(0).st_size)

inp = []
sign = 1.0
numb = 0.0
 
for i in range(len(s)):
    if s[i]>=48:
        numb = 10.0*numb + s[i]-48.0
    else:
        if s[i]==45:
            sign = -1.0
        elif s[i]!=13:
            inp.append(sign*numb)
            numb = 0.0
            sign = 1.0
if s[-1]>=48:
    inp.append(sign*numb)

n,k = int(inp[0]),int(inp[1])
A = inp[2:2+n]
B = inp[2+n:2+2*n]
Binv = [1.0/b for b in B]

turn_data = [0]*n
for i in range(n):
    a = A[i]
    binv = Binv[i]
    #a-t*b>=0
    #t<=a/b
    # Need to be updated at latest
    turn_data[i] = int(a*binv)

a = 0
b = 2*10**12
while a<b:
    c = (a+b)//2
    x = 1.0*c
    updater = [[] for _ in range(k)]
    for i in range(n):
        if turn_data[i]<k:
            updater[turn_data[i]].append(i)

    last_updated = [0]*n
    charge = A[:]

    failed = False
    updater_ind = 0
    for turn in range(k):
        while updater_ind<k and not updater[updater_ind]:updater_ind += 1
        if updater_ind==k:break

        ind = updater[updater_ind].pop()
        val = updater_ind

        #if val>=big:
        #    #Success
        #    break
        if turn>val:
            failed = True
            break
        charge[ind] += x - B[ind]*(turn-last_updated[ind])
        last_updated[ind] = turn
        if turn + charge[ind]*Binv[ind]>=k-1:continue
        next_update = turn + trunc(charge[ind]*Binv[ind])
        if next_update<k-1:
            updater[int(next_update)].append(ind)
    if failed:
        a = c+1
    else:
        b = c
if b == 2*10**12:
    print(-1)
else:
    print(b)