import sys
range = xrange
input = sys.stdin.readline

n,m = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]


#m *= 2
numb = 0
out = []
for i in range(n):
    turns = 0
    a = A[i]
    if numb%m!=0:
        if m-numb%m<=a:
            a -= m-numb%m
            numb += m-numb%m
            turns += 1
        else:
            numb += a
            a = 0
    if a!=0:
        numb += a
        turns += a//m
        a = 0
    out.append(str(turns))
print ' '.join(out)