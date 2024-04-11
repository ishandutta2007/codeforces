import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    s = input()

    bucket = [0]*26
    for c in s:
        bucket[ord(c) - ord('a')] += 1

    nonzero = []
    for i in range(26):
        if bucket[i]:
            nonzero.append((i,bucket[i]))

    for test in [nonzero[::2] + nonzero[1::2], nonzero[1::2] + nonzero[::2]]:
        out = []
        for i,count in test:
            out += [chr(i + ord('a'))]*count
        s = ''.join(out)

        for i in range(len(s)-1):
            if abs(ord(s[i]) - ord(s[i+1]))==1:
                break
        else:
            print s
            break
        continue
    else:
        print 'No answer'