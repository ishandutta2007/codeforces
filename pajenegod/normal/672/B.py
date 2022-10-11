import sys
range = xrange
input = raw_input

n = int(input())
S = input()

if n > 26:
    print -1
else:
    print n - len(set(S))