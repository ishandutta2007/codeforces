import sys, os
input = sys.stdin.readline
range = xrange

def ask(l,r):
    r = min(r,n)
    if l >= r:
        return 0

    os.write(1, '? %d %d\n' % (l + 1, r))
    return r - l - int(input())

def ans(i):
    i += 1
    os.write(1, '! %d\n' % i)

n,t = [int(x) for x in input().split()]

m = 1
while m < n:
    m *= 2

L = [0] * m + list(range(m))
R = [0] * m + list(range(1,m+1))
for i in reversed(range(1,m)):
    L[i] = L[2 * i]
    R[i] = R[2 * i + 1]

seg = [-1] * (2 * m)
for _ in range(t):
    k = int(input())
    if _ == 0:
        seg[1] = ask(0,n)

    i = 1
    while i < m:
        if seg[2 * i] == -1:
            if seg[i] == 0:
                seg[2 * i] = 0
            elif seg[i] == R[i] - L[i]:
                seg[2 * i] = R[2 * i] - L[2 * i]
            else:
                seg[2 * i] = ask(L[2 * i], R[2 * i])
            
            seg[2 * i + 1] = seg[i] - seg[2 * i]
        
        if seg[2 * i] >= k:
            i = 2 * i
        else:
            k  -= seg[2 * i]
            i = 2 * i + 1
    
    ans(i - m)
    
    while i:
        seg[i] -= 1
        i >>= 1