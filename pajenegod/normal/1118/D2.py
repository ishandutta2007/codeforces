import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

A.sort(reverse=True)

a = 1
b = n+1
while a!=b:
    c = (a+b)//2
    count = 0
    cost = 0
    work = 0
    for u in A:
        if u-cost<=0:
            break
        work += u-cost
        count += 1
        if count == c:
            count = 0
            cost += 1
    if work>=m:
        b = c
    else:
        a = c+1
if a==n+1:
    print -1
else:
    print a