import sys
range = xrange
input = raw_input

def mapper(S):
    return [ord(c) - ord('a') for c in S]

def remapper(S):
    return ''.join(chr(c + ord('a')) for c in S)

t = int(input())
for _ in range(t):
    n, k = [int(x) for x in input().split()]
    S = mapper(input())

    bucket = [0] * 30
    for c in S:
        bucket[c] += 1
    
    counts = [0] * (n + 1)
    for y in range(1, n + 1):
        count = 0
        for c in range(30):
            count += bucket[c] // y
        counts[count] = y
    
    best = besty = 0
    for i in reversed(range(1, n + 1)):
        besty = max(besty, counts[i])
        if k % i == 0:
            best = max(best, i * besty)
    print best