import sys
range = xrange
input = raw_input

MOD = 10**9 + 7

n,m = [int(x) for x in input().split()]



print pow(pow(2, m, MOD) - 1, n, MOD)