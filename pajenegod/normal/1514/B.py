import sys
range = xrange
input = raw_input

MOD = 10**9 + 7

t = int(input())
for _ in range(t):
    n,k = [int(x) for x in input().split()]

    print pow(n,k,MOD)