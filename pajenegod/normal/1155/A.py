import sys
range = xrange
input = raw_input

n = int(input())
s = input()

ssort = sorted(list(s))

for i in range(n):
    if ssort[i] != s[i]:
        j = n-1
        while j>i and ssort[i] != s[j]:
            j -= 1
        print 'YES'
        print i+1,j+1
        sys.exit()
else:
    print 'NO'