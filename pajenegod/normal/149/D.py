import sys
range = xrange
input = raw_input

MOD = 1000000007

S = input()
n = len(S)

stack = []
match = [-1]*n

for i in reversed(range(n)):
    if S[i] == ')':
        stack.append(i)
    else:
        j = stack.pop()
        match[i] = j
        match[j] = i

# white LR
# color L
# color R
# color LR

mem = {}
def f(l,r,bound):
    if l>=r:
        return 1
    key = l,r,bound
    
    if key not in mem:
        m = match[l]
        
        ways = 0
        
        my_bound = 1
        fac = 1 if my_bound & bound else 2
        ways += fac * f(l + 1, m, my_bound) * f(m+1, r, ((my_bound & 2) >> 1) + (bound & 2)) 
        
        my_bound = 2
        fac = 1 if my_bound & bound and m+1 == r else 2
        ways += fac * f(l + 1, m, my_bound) * f(m+1, r, ((my_bound & 2) >> 1) + (bound & 2)) 
        
        ways = int(ways % MOD)
        mem[key] = ways
    return mem[key]

print f(0,n,0)