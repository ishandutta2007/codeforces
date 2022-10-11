import sys,collections
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    counter = collections.defaultdict(int)
    for a in A:
        counter[a] += 1
    
    m = len(set(A))
    maxa = max(A, key = counter.__getitem__)
    cmaxa = counter[maxa]
    ans = 0
    ans = max(ans, min(m - 1, cmaxa))
    ans = max(ans, min(m, cmaxa - 1))
    print ans