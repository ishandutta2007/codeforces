import sys
range = xrange
input = raw_input

A = [0]*(10**6+10)

n = int(input())

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

for numb in inp:
    A[numb]+=1

good = []
tot = sum(inp)
for i in range(n):
    numb = inp[i]
    #0 = X - (tot-numb-X)
    Y = tot-numb
    if Y%2==0 and Y>=1 and Y<=2*10**6 and A[Y//2]-(Y//2==numb)>0:
        good.append(i)
print len(good)
print ' '.join(str(x+1) for x in good)