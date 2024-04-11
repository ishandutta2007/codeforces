import sys
range = xrange
input = raw_input

# 2 * b - a
# 2 * b - a - 3

def check(a,b):
    val = -(a - 2 * b)
    k = val//3
    a -= k
    b -= 2 * k

    return k >= 0 and val % 3 == 0 and a >= 0 and b >= 0

out = []
t = int(input())
for _ in range(t):
    a,b = [int(x) for x in sys.stdin.readline().split()]
     
    if check(a,b) or check(b,a):
        print 'YES'
    else:
        print 'NO'