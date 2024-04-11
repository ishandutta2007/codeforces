import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]
ii = 0

t = inp[ii]
ii+=1
for _ in range(t):
    n = inp[ii]
    ii += 1
    x = inp[ii]
    ii += 1

    D = inp[ii:ii+2*n:2]
    H = inp[ii + 1:ii+2*n:2]
    ii += 2*n

    maxdmg = max(D[i] - H[i] for i in range(n))
    maxhit = max(D)

    if maxhit < x and maxdmg <= 0:
        print -1
    elif maxhit >= x:
        print 1
    else:
        print 1 + (x - maxhit + maxdmg - 1)//maxdmg