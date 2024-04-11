import sys
range = xrange
input = raw_input

n = int(input())

C = []
SUM = []
for _ in range(n):
    c,sumi = [int(x) for x in input().split()]
    
    
    low = sumi // c
    high = low + 1

    highs = sumi % c
    lows = c - highs

    print low * low * lows + high * high * highs