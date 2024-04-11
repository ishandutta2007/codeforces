import sys
range = xrange
input = raw_input

n = int(input())
s = [int(x) for x in input()]

left = n

i = 0
j = 0
turn = 0
while left>11:
    if turn == 0:
        while i<n and (s[i]==8 or s[i]==-1): i += 1
        if i == n:
            print 'YES'
            sys.exit()
        s[i] = -1
        i += 1
    else:
        while j<n and s[j]!=8: j += 1
        if j==n:
            print 'NO'
            sys.exit()
        s[j] = -1
        j += 1
    turn ^= 1
    left -= 1

s = [c for c in s if c>=0]
assert len(s) == left
if s and s[0]==8:
    print 'YES'
else:
    print 'NO'