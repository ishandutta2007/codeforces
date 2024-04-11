import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    x = int(input())

    A = [10]
    while x:
        A.append(min(x,9,A[-1]-1))
        x -= A[-1]
        if A[-1] == 0:
            print -1
            break
    else:
        print ''.join(str(x) for x in A[1:][::-1])