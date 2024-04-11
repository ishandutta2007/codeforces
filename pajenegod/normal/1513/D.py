import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,p = [int(x) for x in input().split()]

    L = [0]
    R = [n]

    A = [int(x) for x in input().split()]

    order = sorted(range(n), key = A.__getitem__)
    where = [0] * n

    total = 0

    for i in order:
        a = A[i]
        ind = where[i]

        #print 'working with i = ', i, 'and A[i] =', A[i], 'with ind', ind

        if ind == -1:
            continue

        l = L[ind]
        r = R[ind]

        if l + 1 >= r:
            continue

        if p <= a:
            total += p * (r - l - 1)
            L[ind] = R[ind] = -1

        else:
            li = i
            ri = i
            while l < li and A[li - 1] % a == 0:
                li -= 1

            while ri + 1 < r and A[ri + 1] % a == 0:
                ri += 1

            #print 'Interval found li,ri', li,ri

            total += a * (ri - li)

            if l < i == li:
                li -= 1
                total += p

            if i == ri < r - 1:
                ri += 1
                total += p
            
            #print 'Modified interval found li,ri', li,ri

            for j in range(li + 1, ri):
                where[j] = -1

            l1, r1 = l, li + 1
            l2, r2 = ri, r

            if r1 - l1 < r2 - l2:
                l1,r1,l2,r2 = l2,r2,l1,r1

            L[ind] = l1
            R[ind] = r1

            ind2 = len(L)
            L.append(l2)
            R.append(r2)

            for j in range(l2,r2):
                where[j] = ind2

    print total