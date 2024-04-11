import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,k = [int(x) for x in input().split()]
    S = list(input())
    S.sort()

    if k != n and all(c == S[0] for c in S[:k]):
        if all(c == S[k] for c in S[k:]):
            print S[k - 1] + S[k] * (((n - k) + k - 1) // k)
        else:
            print ''.join(S[k - 1:])
    else:
        print S[k - 1]