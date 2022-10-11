import sys
range = xrange
input = raw_input

q = int(input())
for _ in range(q):
    a,b,m = [int(x) for x in input().split()]

    if a == b:
        print 1
        print a
        continue

    l = 1
    r = 50
    while l < r:
        mid = l + r + 1 >> 1
        
        LHS = b - (a << (mid - 2))
        RHS = 1 << (mid - 2)

        if LHS >= RHS:
            l = mid
        else:
            r = mid - 1

    if l == 1:
        print -1
        sys.exit()

    n = l

    LHS = b - (a << (n - 2))
    RHS = 1 << (n - 2)

    R = [1]*n
    R[0] = a
    for j in reversed(range(n - 2)):
        i = n - 2 - j
        
        power = 1 << j
        dx = min((LHS - RHS)//power, m - 1)
        R[i] += dx
        RHS += dx * power

    i = n - 1
    power = 1   
    dx = min((LHS - RHS)//power, m - 1)
    R[i] += dx
    RHS += dx * power

    X = [a]
    for i in range(1,n):
        X.append(sum(X) + R[i])
    
    if X[0] == a and X[-1] == b:
        print n, ' '.join(str(x) for x in X)
    else:
        print -1