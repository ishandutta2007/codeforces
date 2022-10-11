import sys
range = xrange
input = sys.stdin.readline

n = int(input())

m = n
i = 0
count = 0
while 2**i<=m:
    m-=2**i
    i+=1
    count += 1
if m>0:
    count += 1
print count