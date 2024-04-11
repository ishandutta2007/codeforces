import sys
range = xrange
input = raw_input

n = int(input())
H = [int(x) for x in input().split()]

DP = [n] * n
DP[0] = 0

inc_stack = []
dec_stack = []

for i in range(n):
    h = H[i]
   
    bad = False
    while inc_stack and H[inc_stack[-1]] >= h:
        j = inc_stack.pop()
        DP[i] = min(DP[i], DP[j] + 1)
        bad = H[j] == h

    if not bad and inc_stack:
        j = inc_stack[-1]
        DP[i] = min(DP[i], DP[j] + 1)

    bad = False
    while dec_stack and H[dec_stack[-1]] <= h:
        j = dec_stack.pop()
        DP[i] = min(DP[i], DP[j] + 1)
        bad = H[j] == h
    
    if not bad and dec_stack:
        j = dec_stack[-1]
        DP[i] = min(DP[i], DP[j] + 1)

   
    inc_stack.append(i)
    dec_stack.append(i)
print DP[-1]