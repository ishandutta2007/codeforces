import sys
range = xrange
input = raw_input

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

inp.sort()

B = []
prev = inp[0]
count = 0
for a in inp:
    if prev!=a:
        B.append(count)
        count = 0
    count += 1
    prev = a
B.append(count)

B.sort()

m = len(B)

base = 1
i = 0

maxfound = 0

while True:
    while i<m and B[i]<base:
        i+=1
    if i>=m:break
    
    j = i
    base2 = base
    found = 0
    while j<m:
        if B[j]>=base2:
            found += base2
            base2*=2
        j+=1
    base += 1
    maxfound = max(maxfound,found)
print maxfound