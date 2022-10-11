
import sys
range = xrange
input = raw_input

rint = lambda: int(input())
rints = lambda: [int(x) for x in input().split()]

t = int(input())
for _ in range(t):
    n = rint()
    A = rints()
    
    i = 0
    j = n - 1
    da = ea = 0
    db = eb = 0
    turn = 1
    moves = 0
    while i <= j:
        if turn:
            da = 0
            while da <= db and i <= j:
                da += A[i]
                i += 1
            ea += da
        else:
            db = 0
            while db <= da and i <= j:
                db += A[j]
                j -= 1
            eb += db
        moves += 1
        turn ^= 1
    print moves,ea,eb