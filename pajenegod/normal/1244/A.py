import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    a,b,c,d,k = [int(x) for x in input().split()]

    count = (a + c - 1)//c + (b + d - 1)//d
    if count > k:
        print -1
    else:
        print (a + c - 1)//c, (b + d - 1)//d