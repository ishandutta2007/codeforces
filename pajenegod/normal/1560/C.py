import sys
input = raw_input

t = int(input())
for _ in range(t):
    k = int(input())
    
    i = 0
    while k - (2 * i + 1) > 0:
        k -= (2 * i + 1)
        i += 1

    if k <= i:
        print k, i + 1
    else:
        print i + 1, 2*i + 2 - k