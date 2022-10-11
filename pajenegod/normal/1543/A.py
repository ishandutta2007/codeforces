import sys
range = xrange
input = raw_input

def gcd(a,b):
    while b:
        a,b = b,a%b
    return a

t = int(input())
for _ in range(t):
    a,b = [int(x) for x in input().split()]
    goal = max(a,b) - min(a,b)
    
    print goal, (min(a%goal, -a%goal) if goal != 0 else 0)