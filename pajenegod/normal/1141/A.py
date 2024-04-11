import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]

if m%n!=0 or n>m:
    print -1
    sys.exit()

a = m//n
count = 0
while a%2==0:
    a//=2
    count += 1
while a%3==0:
    a//=3
    count += 1

if a==1:
    print count
else:
    print -1