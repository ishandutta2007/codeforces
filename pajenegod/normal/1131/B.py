import sys
range = xrange
input = raw_input

n = int(input())
inp = [0,0]+[int(x) for x in sys.stdin.read().split()]
A = inp[::2]
B = inp[1::2]

count = 1
for i in range(n):
    a = A[i]
    b = B[i]
    c = A[i+1]
    d = B[i+1]
    
    x = max(a,b)
    y = min(c,d)
    
    if x>y:continue
    if a<x or b<x:
        count += 1
     
    count += y-x
print count