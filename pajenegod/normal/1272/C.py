import sys
range = xrange
input = raw_input

orda = ord('a')

n,k = [int(x) for x in input().split()]
S = [ord(c) - orda for c in input()]
K = [ord(c) - orda for c in input().split()]

write = [0]*30
for c in K:
    write[c] = 1

subs = 0
first = 0
for i in range(n):
    if write[S[i]]:
        subs += i - first + 1   
    else:
        first = i + 1

print subs