import sys
range = xrange
input = raw_input

alpha = 'abcdefghijklmnopqrstuvwxyz'

t = int(input())
for _ in range(t):
    S = input()
    n = len(S)

    mid = S.index(min(S))
    left = S[:mid][::-1]
    right = S[mid:]

    if set(left) | set(right) == set(alpha[:n]) and left == ''.join(sorted(left)) and right == ''.join(sorted(right)):
        print 'YES'
    else:
        print 'NO'