import sys
from collections import defaultdict as di
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]

s = sys.stdin.read()
inp = []
numb = 0
 
for i in range(len(s)):
    if s[i]>='0':
        numb = 10*numb + ord(s[i])-48
    else:
        inp.append(numb)
        numb = 0
if s[-1]>='0':
    inp.append(numb)


S = inp


A = [0]*(2*10**5+10)
numbs = []

for s in S:
    if A[s]==0:
        numbs.append(s)
    A[s]+=1

a = 1
b = n

while a!=b:
    mid = (a+b+1)//2

    count = 0
    for s in numbs:
        count += A[s]//mid
    if count>=k:
        a = mid
    else:
        b = mid-1
out = []
for s in numbs:
    for _ in range(A[s]//a):
        out.append(s)
print ' '.join(str(x) for x in out[:k])