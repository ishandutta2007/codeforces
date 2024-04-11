import sys
range = xrange
input = raw_input

n = int(input())

div = []
m = 2
while m*m<=n:
    if n%m==0:
        div.append(m)
    m+=1

vals = [1]

for d in div:
    d = n//d
    m = n//d
    val = d*(m*(m-1)//2) + m
    vals.append(val)

for d in div:
    m = n//d
    val = d*(m*(m-1)//2) + m
    vals.append(val)

vals.append(n*(n+1)//2)

vals = sorted(set(vals))
print ' '.join(str(x) for x in vals)