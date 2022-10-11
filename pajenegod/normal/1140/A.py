import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x)-1 for x in input().split()]

maxi = 0
i = -1
days = 0
while i+1<n:
    days += 1
    while i+1<n and i<maxi:
        i += 1
        maxi = max(maxi,A[i])
    maxi = i+1
print days