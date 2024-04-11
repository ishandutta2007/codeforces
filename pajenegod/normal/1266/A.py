import sys
range = xrange
input = raw_input

n = int(input())
for _ in range(n):
    X = [int(x) for x in input()]

    #42,4,6,8
    #0,
    X.sort(reverse=True)
    zero = X.pop()

    if zero == 0 and (0 in X or 2 in X or 4 in X or 6 in X or 8 in X) and sum(X)%3 == 0:
        print 'red'
    else:
        print 'cyan'