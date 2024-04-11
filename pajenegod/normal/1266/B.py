import sys
range = xrange
input = raw_input

bot = [1,2,3,4,5,6]

t = int(input())
for x in [int(x) for x in input().split()]:
    for i in bot:
        y = x - (21 - i)
        if y >= 0 and y%14 == 0:
            print 'YES'
            break
    else:
        print 'NO'