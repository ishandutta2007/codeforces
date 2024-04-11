import sys
range = xrange
input = raw_input

n = int(input())
A = tuple([int(x)-1 for x in input().split()])

pick2 = {
    (0,1) : 3,
    (0,2) : 4,
    (1,0) : 3,
    (2,0) : 4,
    
    (1,2) : -1,
    (2,1) : -1,

    (0,0) : -1,
    (1,1) : -1,
    (2,2) : -1
}

s = 0
for i in range(n-1):
    pair = (A[i],A[i+1])
    val = pick2[pair]
    if val == -1:
        print 'Infinite'
        sys.exit()
    if i>0 and A[i-1:i+2] == (2,0,1):
        val -= 1
    
    s += val

print 'Finite'
print s