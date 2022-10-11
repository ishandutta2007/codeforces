import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
p = inp[ii]; ii += 1
k = inp[ii]; ii += 1

# HAIR
B = inp[ii::2]
# DISPLEASEMENT
A = inp[ii+1::2]

worst = []
order = list(range(n))


if p != k:
    order.sort(key = lambda i: (-A[i],B[i]))
    worst += order[-(p-k):]
    del order[-(p-k):]

order.sort(key = lambda i: (B[i], A[i]))
pick = order[-k:]

if p != k:
    del order[-k:]

    threshhold = max((-A[i], B[i]) for i in pick) 
    order += worst
    order = [i for i in order if (-A[i],B[i]) >= threshhold]

    order.sort(key = lambda i: (-A[i],B[i]))
    pick += order[:p-k]


print ' '.join(str(x + 1) for x in pick)


def checker(pick):
    print 'checking', ' '.join(str(x+1) for x in pick)
    pick.sort(key = lambda i: (-A[i], B[i]))

    asum = 0
    bsum = 0
    for i in pick[:k]:
        #asum += A[i]
        bsum += B[i]

    for i in pick[k:]:
        asum += A[i]
        #bsum += B[i]
    print asum,bsum

#checker(pick)
#checker([0,3,7,2,4,6,9])