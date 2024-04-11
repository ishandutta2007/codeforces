import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    ord0 = ord('0')
    S = [ord(c) - ord0 for c in input()]
    
    sumS = sum(S)
    if sumS == 0:
        print n
    else:
        i = 0
        while not S[i]: i += 1
        j = n - 1
        while not S[j]: j -= 1

        print max(n + sumS, 2 * (n - i), 2 * (j + 1))