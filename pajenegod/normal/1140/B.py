import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    i = 0
    while i<n and s[i]!='>':
        i += 1
    j = n-1
    while j>=0 and s[j]!='<':
        j -= 1

    score = min(i,n-1-j,n-1)
    print score