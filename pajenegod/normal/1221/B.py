import sys
range = xrange
input = raw_input

n = int(input())
line1 = ('WB'*n)[:n]
line2 = ('BW'*n)[:n]
for _ in range(n):
    print line1 if _&1 else line2