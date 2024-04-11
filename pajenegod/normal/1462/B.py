import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input()]

    if n < 4:
        print 'NO'
        continue

    count = 0
    for i,x in enumerate([2,0,2,0]):
        if A[i] != x:
            break
        count += 1
    
    for i,x in enumerate([2,0,2,0][::-1]):
        if A[~i] != x:
            break
        count += 1

    print 'YES' if count >= 4 else 'NO'