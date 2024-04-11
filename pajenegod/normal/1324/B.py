import sys, collections
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    counter = collections.defaultdict(int)
    prev = -1
    for a in A:
        counter[a] += 1
        if (counter[a] == 2 and prev != a) or (counter[a] >= 3):
            print 'YES'
            break
        prev = a
    else:
        print 'NO'