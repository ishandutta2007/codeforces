import sys
range = xrange
input = raw_input

q = int(input())

for _ in range(q):
    n = int(input())
    s = input()

    s1 = s[:1]
    s2 = s[1:]
    if len(s1)<len(s2) or int(s1)<int(s2):
        print 'YES'
        print 2
        print s1,s2
    else:
        print 'NO'