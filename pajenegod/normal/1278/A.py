import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    p = [ord(c) - ord('a') for c in input()]
    h = [ord(c) - ord('a') for c in input()]

    if len(h) < len(p):
        print 'NO'
        continue

    counts = [0]*26
    for c in p:
        counts[c] += 1

    for i in range(len(p)):
        counts[h[i]] -= 1

    if all(c==0 for c in counts):
        print 'YES'
        continue

    i = 0
    while i + len(p) < len(h):
        counts[h[i]] += 1
        counts[h[i + len(p)]] -= 1
        i += 1
        
        if all(c==0 for c in counts):
            print 'YES'
            break
    else:
        print 'NO'