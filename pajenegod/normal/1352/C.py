import sys
range = xrange
input = raw_input

rint = lambda: int(input())
rints = lambda: [int(x) for x in input().split()]

t = int(input())
for _ in range(t):
    n,k = rints()
    k -= 1

    ind = 1
    x,k = divmod(k,n - 1)
    ind += x * n
    print ind + k