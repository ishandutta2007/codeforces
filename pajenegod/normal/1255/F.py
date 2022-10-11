import sys
range = xrange
input = raw_input

def query1(a,b,c):
    print 1, a+1, b+1, c+1
    return int(input())
def query2(a,b,c):
    print 2, a+1, b+1, c+1
    return int(input())
def ans(order):
    print 0,' '.join(str(x + 1) for x in order)
    sys.exit()

n = int(input())

a = 0
b = 1
for i in range(2,n):
    if query2(a,b,i) < 0:
        b = i
A = [-1]*n
for i in range(1,n):
    if i != b:
        A[i] = query1(a,b,i)


order = sorted(range(n), key = A.__getitem__)
j = order[-1]

left = []
right = [a,b]
for i in order:
    if i != a and i != b and i != j:
        (left if query2(a,j,i) >= 0 else right).append(i)
right.append(j)

right += reversed(left)
ans(right)