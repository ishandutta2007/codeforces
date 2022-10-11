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

L = [0] * n + list(range(n))
R = [0] * n + list(range(1,n+1))
for i in reversed(range(1,n)):
    L[i] = L[2 * i]
    R[i] = R[2 * i + 1]

inters1 = []
inters2 = []
l = n
r = 2 * n
while l < r:
    if l & 1:
        inters1.append(l)
        l += 1
    if r & 1:
        r -= 1
        inters2.append(r)
    l >>= 1
    r >>= 1

inters = inters1 + inters2[::-1]

seg = [-1] * (2 * n)
for _ in range(t):
    k = int(input())
    
    for i in inters:
        if seg[i] == -1:
            if n - L[i] == k:
                seg[i] = R[i] - L[i]
            else: 
                seg[i] = ask(L[i], R[i])
        if seg[i] >= k:
            break
        k -= seg[i]

    while i < n:
        if seg[2 * i] == -1:
            if seg[i] == 0:
                seg[2 * i] = 0
            elif seg[i] == R[i] - L[i] or R[i] - L[i] == k:
                seg[2 * i] = R[2 * i] - L[2 * i]
            else:
                seg[2 * i] = ask(L[2 * i], R[2 * i])
            
            seg[2 * i + 1] = seg[i] - seg[2 * i]
        
        if seg[2 * i] >= k:
            i = 2 * i
        else:
            k  -= seg[2 * i]
            i = 2 * i + 1
    
    ans(i - n)
    
    while i:
        seg[i] -= 1
        i >>= 1