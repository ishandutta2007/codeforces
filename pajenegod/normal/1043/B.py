import sys
range = xrange
input = sys.stdin.readline

n = int(input())

n += 1
A = [0]+[int(x) for x in input().split()]

for i in reversed(range(1,n)):
    A[i] -= A[i-1]

n -= 1
A = A[1:]

out = []
for k in range(1,n+1):
    for i in range(n):
        if i+k<n and A[i] != A[i+k]:
            break
    else:
        out.append(k)

print len(out)
print ' '.join(str(x) for x in out)