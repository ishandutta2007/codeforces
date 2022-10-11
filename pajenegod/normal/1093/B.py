import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    s = input()
    n = len(s)

    if not all(c==s[0] for c in s):
        print ''.join(sorted(s))
    else:
        print -1