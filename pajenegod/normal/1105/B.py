import sys
from collections import defaultdict as di
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]
S = input()

char_pos = di(list)
for i in range(n):
    char_pos[S[i]].append(i)

maxi = 0
for c in char_pos:
    A = char_pos[c]
    l = 0
    count = 0
    for i in reversed(A):
        if count == 0 or last_pos-1!=i:
            count = 1
            last_pos = i
        else:
            count += 1
            last_pos -= 1
        if count == k:
            l += 1
            count = 0
    maxi = max(maxi,l)
print maxi