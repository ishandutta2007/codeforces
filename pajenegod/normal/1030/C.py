import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input()]

s = sum(A)
for goal in range(s + 1):
    x = 0
    count = 0
    for i in range(n):
        x += A[i]
        if x >= goal:
            if x > goal:
                break
            count += 1
            x = 0
    else:
        if count > 1 and x == 0:
            print 'YES'
            break
else:
    print 'NO'