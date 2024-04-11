import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    k = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n
    
    used = [0]*100
    for a in A:
        i = 0
        while a:
            d,m = divmod(a, k)
            if m > 1 or (m == 1 and used[i]):
                print 'NO'
                break
            if m == 1:
                used[i] = 1
            a = d
            i += 1
        else:
            continue
        break
    else:
        print 'YES'