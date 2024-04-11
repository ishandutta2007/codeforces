import sys
range = xrange
input = raw_input

n = int(input())
S = [ord(c) - ord('a') for c in input()]

C = [0]*n
buckets = [[] for _ in range(26)]
for i in range(n):
    buckets[S[i]].append(i)

for a in range(26):
    i = 0
    for b in range(26):
        bucket = buckets[b]
        while bucket and C[bucket[-1]] != 0: bucket.pop()
        if not bucket or bucket[-1] < i:
            continue

        goal = bucket[-1] + 1
        while i < goal:
            if S[i] == b:
                C[i] = a + 1
            i += 1

if max(C) <= 2:
    print 'YES'
    print ''.join(str(x - 1) for x in C)
else:
    print 'NO'