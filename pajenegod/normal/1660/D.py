import sys

def f(x,y):
    sign = 2 * ((x * y) > 0) - 1
    return sign * (abs(x) + abs(y) - 1)

def solve(l, r):
    if l == r:
        return (1, l, r)
    
    if r - l == 1:
        return max((A[l], l, r), (1,0,0))

    mid = (r + l) // 2
    best = (1,0,0)

    best = max(best, solve(l, mid))
    best = max(best, solve(mid, r))
    
    prefix = []
    prod = 1
    for i in range(mid, r):
        prod = f(prod, A[i])
        prefix.append(prod)
   
    suffix = []
    prod = 1
    for i in reversed(range(l, mid)):
        prod = f(prod, A[i])
        suffix.append(prod)
    
    i = min(range(r - mid), key = prefix.__getitem__)
    j = min(range(mid - l), key = suffix.__getitem__)
    ll = mid - 1 - j
    rr = mid + i
    best = max(best, (f(prefix[i], suffix[j]), ll, rr + 1))

    i = max(range(r - mid), key = prefix.__getitem__)
    j = max(range(mid - l), key = suffix.__getitem__)
    ll = mid - 1 - j
    rr = mid + i
    best = max(best, (f(prefix[i], suffix[j]), ll, rr + 1))
    
    return best


inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n
    
    i = j = 0
    best = (1,0,0)
    while True:
        while i < n and A[i] == 0:
            i += 1
        if i == n:
            break
        j = i
        while j < n and A[j] != 0:
            j += 1

        best = max(best, solve(i, j))
        i = j
    
    _,l,r = best
    print l, n-r