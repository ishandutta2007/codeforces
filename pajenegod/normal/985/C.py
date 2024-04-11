import sys
range = xrange
input = raw_input

n,k,l = [int(x) for x in input().split()]
# n barrels
# k staves each

# v_j = minimum stave

# abs(v_i-v_j) <= l

# m = n*k
A = [int(x) for x in input().split()]
A.sort()


j = 0
smallest = A[0]

while j<n*k and A[j]-A[0]<=l:
    j+=1

if j<n:
    print 0
    sys.exit()

best_case = []
for i in range(n):
    best_case.append(A[i*k])

other_case = []
for i in range(j-n,j):
    other_case.append(A[i])

summa = 0
for i in range(n):
    summa += min(best_case[i],other_case[i])
print summa