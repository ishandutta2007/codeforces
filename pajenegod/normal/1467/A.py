import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    print '9' + ''.join(str((i + 8)%10) for i in range(n - 1))