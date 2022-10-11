import sys
range = xrange
input = sys.stdin.readline

n,m = [int(x) for x in input().split()]
A = [int(x)-1 for x in input().split()]

counter = 0
found = [0]*n

out = []
for a in A:
    found[a] += 1
    if found[a]==1:
        counter += 1
    if counter == n:
        out.append(1)
        for i in range(n):
            found[i]-=1
            if found[i]==0:
                counter-=1
    else:
        out.append(0)
print ''.join(str(x) for x in out)