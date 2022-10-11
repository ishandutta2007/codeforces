import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

a = 1
b = max(A)
while a < b:
    c = a + b >> 1

    ii = 0
    picked = 0
    while ii < n:
        if A[ii] <= c:
            picked += 1
            ii += 1
            picked += ii < n
        ii += 1
    
    
    picked2 = picked
    picked = 1
    ii = 1
    while ii < n:
        if A[ii] <= c:
            picked += 1
            ii += 1
            picked += ii < n
        ii += 1
    
    if max(picked, picked2) >= k:
        b = c
    else:
        a = c + 1

print a