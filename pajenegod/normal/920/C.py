input = raw_input
range = xrange

n = int(input())
A = [int(x) for x in input().split()]
s = [c=='1' for c in input()]
s.append(False)

vals = [0]*n

indl = 0
count = 0
while indl<n:
    indr = indl
    while s[indr]:
        indr += 1
    for i in range(indl,indr+1):
        vals[i] = count
    indl=indr+1
    count += 1

Asort = sorted(A)
Asort2 = sorted(zip(vals,A))

for i in range(n):
    if Asort[i]!=Asort2[i][1]:
        print 'NO'
        break
else:
    print 'YES'