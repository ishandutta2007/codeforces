import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    s = input()
    if len(s) % 2 == 0 and s[0] != ')' and s[-1] != '(':
        print 'YES'
    else:
        print 'NO'