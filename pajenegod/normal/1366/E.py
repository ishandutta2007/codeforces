import sys
range = xrange
input = raw_input

MOD = 998244353
def printer(x):
    print int(x) % MOD
    sys.exit()

n,m = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

newA = []
mina = 10**9 + 10
for a in reversed(A):
    if a <= mina:
        mina = a
        newA.append(a)
    else:
        newA.append(-1)
newA.reverse()
A = newA

first = [-1]*m
last = [-1]*m
for i in range(n):
    a = A[i]
    if a < 0:
        continue

    l = -1
    r = len(B) - 1
    while l < r:
        mid = l + r + 1 >> 1
        if a < B[mid]:
            r = mid - 1
        else:
            l = mid
    if l == -1:
        printer(0)
    
    last[l] = i
    if a == B[l]:
        first[l] = i

if any(f < 0 for f in first):
    printer(0)

ans = 1
for i in range(m - 1):
    a = last[i]
    b = first[i + 1]
    ans = ans * (b - a) % MOD
printer(ans)