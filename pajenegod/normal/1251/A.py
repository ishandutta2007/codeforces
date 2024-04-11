import sys
range = xrange
input = raw_input

t = int(input())

for _ in range(t):
    s = input()
    n = len(s)

    good = set()

    i = 0
    while i < n:
        j = i
        while j<n and s[j] == s[i]:
            j += 1
        if (j - i) & 1:
            good.add(s[i])
        i = j

    print ''.join(c for c in sorted(good))