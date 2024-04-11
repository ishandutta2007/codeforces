import sys
s = sys.stdin.read()

j = 0
inp = []
numb = 0

while j<len(s)-1:
    numb = 10*numb + ord(s[j])-48
    j+=1
    
    if s[j]<'-':
        inp.append(numb)
        j+=1
        numb=0
if j==len(s)-1:
    numb = 10*numb + ord(s[j])-48
    inp.append(numb)
ii = 0

n,m = inp[ii],inp[ii+1]
ii+=2

ANS = inp[ii:ii+n]
ii+=n
temp = [inp[ii+n*_:ii+n*(_+1)] for _ in range(m-1)]
r = [[0]*(n+1) for _ in range(m-1)]
for j in range(len(temp)):
    for i in range(n):
        r[j][temp[j][i]] = i

de = [False]*(n-1)
for i in range(n-1):
    a = ANS[i]
    b = ANS[i+1]
    ch = False
    for rr in r:
        if rr[a] != rr[b]-1:
            ch = True
            break
    de[i] = ch

outs = []
cnt = 0
for x in de:
    if not x:
        cnt += 1
    else:
        outs.append(cnt)
        cnt = 0
outs.append(cnt)
ans = n
for o in outs:
    ans += o*(o+1)/2
print ans