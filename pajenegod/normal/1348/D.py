import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
#for n in range(2, 10**4):
    
    m = 1
    bac = 1
    days = []
    
    while m < n:
#        print days, n, m ,bac
        if m + 2 * bac >= n:
            extra = n - m - bac
            days.append(extra)
            assert(0 <= extra <= bac)
            bac += extra
            m += bac
        else:
            extra = (n + 3)//4 - bac
            extra = min(extra, bac)
            extra = max(extra, 0)

            assert(0 <= extra <= bac)
            days.append(extra)
            bac += extra
            m += bac
    assert(n == m)
    print len(days)
    print ' '.join(str(x) for x in days)