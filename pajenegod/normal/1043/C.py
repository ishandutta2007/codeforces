import sys
range = xrange
input = raw_input

s = input()

n = len(s)

moves = [0]*n

for i in range(1,n):
    if s[i]=='a':
        moves[i-1] += 1
        moves[i] = 1

print ' '.join(str(x%2) for x in moves)