import sys
range = xrange
input = raw_input

n,m,k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

A.sort()

hap = 0

count = m//(k+1)
hap += A[-1]*count*k + A[-2]*count
m %= k+1
hap += A[-1]*m

print hap