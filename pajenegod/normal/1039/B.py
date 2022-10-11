import sys
import random
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]

L = 0
R = n

while True:
    if R-L>100:
        M = (L+R)//2
        print L+1,M+1
        sys.stdout.flush()
        inp = input()
        if inp=='Yes':
            L,R = L,M+1
        else:
            L,R = M+1,R
    else:
        i = L+random.randint(0,R-L-1)
        print i+1,i+1
        sys.stdout.flush()
        inp = input()
        if inp=='Yes':
            sys.exit()

    R = min(R+k,n)
    L = max(L-k,0)