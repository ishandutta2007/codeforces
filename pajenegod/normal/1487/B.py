import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,k = [int(x) for x in input().split()]
    k -= 1

    if n & 1 == 0 or k < n//2:
        print (k % n) + 1
    else:
        x = n//2 + 1
        k -= n//2

        x += k//(n//2) + k
        print (x % n) + 1