import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]
k-=1

throws = 1+n

walks = min(k,n-k-1)

picks = n

moves = n-1

print picks + moves + throws + walks