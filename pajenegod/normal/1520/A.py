import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    S = input()
    
    for c in set(S):
        i = S.index(c)
        j = S.rindex(c)
        count = S.count(c)
        if j - i + 1 != count:
            print 'NO'
            break
    else:
        print 'YES'