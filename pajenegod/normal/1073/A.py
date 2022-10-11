import sys
range = xrange
input = raw_input

n = int(input())

s = input()

for i in range(n-1):
    if s[i]!=s[i+1]:
        print 'YES'
        print s[i:i+2]
        sys.exit()
print 'NO'