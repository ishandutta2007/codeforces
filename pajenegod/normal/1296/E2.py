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

print max(C)
print ' '.join(str(x) for x in C)