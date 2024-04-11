import sys
range = xrange
input = raw_input

n = int(input())
F = [int(x)-1 for x in input().split()]

for i in range(n):
    if i==F[F[F[i]]]:
        print 'YES'
        sys.exit()
print 'NO'