import sys
range = xrange
input = raw_input

t = int(input())

for _ in range(t):
    S = [ord(c) - ord('a') for c in input()]
    n = len(S)

    prev = S[0]
    perfect = [prev]
    for i in range(1, n):
        c = S[i]
        if c in perfect:
            if abs(perfect.index(prev) - perfect.index(c)) > 1:
                print 'NO'
                break
        else:
            j = perfect.index(prev)
            if j == 0:
                perfect.insert(0, c)
            elif j == len(perfect) - 1:
                perfect.append(c)
            else:
                print 'NO'
                break
        prev = c
    else:
        print 'YES'
        for c in range(26):
            if c not in perfect:
                perfect.append(c)
        print ''.join(chr(c + ord('a')) for c in perfect)