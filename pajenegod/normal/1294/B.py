import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    X = inp[ii + 0: ii + 2 * n: 2]
    Y = inp[ii + 1: ii + 2 * n: 2]
    ii += 2 * n

    order = sorted(range(n), key = lambda i: (X[i], Y[i]))
    for i in range(n - 1):
        if Y[order[i]] > Y[order[i + 1]]:
            print 'NO'
            break
    else:
        print 'YES'
        ans = []
        x = y = 0
        for i in range(n):
            xgoal = X[order[i]]
            ygoal = Y[order[i]]
            while x < xgoal:
                ans.append(0)
                x += 1
            while y < ygoal:
                ans.append(1)
                y += 1
        print ''.join('U' if x else 'R' for x in ans)