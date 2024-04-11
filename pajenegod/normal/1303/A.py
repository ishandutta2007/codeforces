import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    S = input()
    n = len(S)

    i = 0
    while i < n and S[i] == '0':
        i += 1

    j = n - 1
    while j >= 0 and S[j] == '0':
        j -= 1

    if i >= j:
        print 0
        continue

    print sum(+(c == '0') for c in S[i:j])