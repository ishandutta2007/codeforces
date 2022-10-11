import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,x = [int(y) for y in input().split()]
    A = [int(y) for y in input().split()]
    
    Acumsum = [0]
    for a in A:
        Acumsum.append((a + Acumsum[-1]) % x)

    if Acumsum[0] != Acumsum[-1]:
        print n
    else:
        i = 0
        while i <= n and Acumsum[i] == Acumsum[0]:
            i += 1
        if i > n:
            print -1
            continue
        j = n
        while j >= 0 and Acumsum[j] == Acumsum[0]:
            j -= 1
        print max(n - i, j)