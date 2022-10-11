import sys
range = xrange
input = raw_input


n,m = [int(_) for _ in input().split()]
x,k,y = [int(_) for _ in input().split()]

def solve(A):
    n = len(A) - 2
    maxi = max(range(len(A)), key = A.__getitem__)
    if 0 < maxi < len(A) - 1 and n < k:
        print -1
        sys.exit()

    cheapduel = y * k < x
    if cheapduel and (maxi == 0 or maxi == len(A) - 1):
        return n * y
    if cheapduel:
        return y * (n - k) + x
    return y * (n % k) + x * (n // k)

A = [int(_) for _ in input().split()]
B = [int(_) for _ in input().split()]
A.insert(0,-1)
A.append(-1)
B.append(-1)

cost = 0
i = 1
j = 0
while i < n + 2:
    starti = i - 1
    while A[i] != B[j]:
        i += 1
        if i == len(A):
            print -1
            sys.exit()
    i += 1
    j += 1
    piece = A[starti:i]
    if len(piece) > 2:
        cost += solve(piece)
if j != len(B):
    print -1,'va'
    sys.exit()    

print cost