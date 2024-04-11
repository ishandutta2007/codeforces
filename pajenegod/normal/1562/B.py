import sys
input = raw_input

import itertools
def subsequence(S):
    ans = []
    for k in range(1, len(S) + 1):
        for s in itertools.combinations(S, k):
            ans.append(''.join(s))
    return ans

big = 10**4
is_prime = [1] * big
for i in range(2, big):
    if is_prime[i]:
        for j in range(i * i, big, i):
            is_prime[j] = 0
is_prime[1] = 0

t = int(input())
for _ in range(t):
    input()
    n = input()
    for c in '14689':
        if c in n:
            print 1
            print c
            break
    else:
        for c in '2357':
            if n.count(c) >= 2:
                print 2
                print c + c
                break
        else:
            ans = min((s for s in subsequence(n) if not is_prime[int(s)]), key = lambda i: len(i))
            print len(ans)
            print ans