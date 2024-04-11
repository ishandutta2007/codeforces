import sys
range = xrange
input = raw_input

n = int(input())


s = input()
for i in range(2,n+1):
    if n%i==0:
        s = s[:i][::-1]+s[i:]
print s