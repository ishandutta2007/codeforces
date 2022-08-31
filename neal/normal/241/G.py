N = 500

print N
X = 0
P = 500

for i in xrange(N):
    if i == 0:
        print 0, 1000000
        X += 250000
    elif i == N - 1:
        print 1000000, 1000000
    else:
        print X, P
        X += 900
        P -= 1