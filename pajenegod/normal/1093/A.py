import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    x = int(input())
    ans = 0
    if x%2==1:
        ans += 1
        x -= 3
    ans += x//2
    print ans