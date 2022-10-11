import sys
range = xrange
input = raw_input

# SPEEEEEEED

H,n = [float(x) for x in input().split()]
Hcopy = H
n = int(n)

D = [float(x) for x in input().split()]

Hmin = H
# Try one iteration
for i,d in enumerate(D):
    if H<=0:
        print i
        sys.exit()
    Hmin = min(H,Hmin)
    H += d
H = Hcopy

Dsum = sum(D)
if Dsum>=0:
    print -1
    sys.exit()

rounds = (int(Hmin)+int(-Dsum)-1)//int(-Dsum)

H += rounds*Dsum
for i,d in enumerate(D):
    if H<=0:
        break
    H += d
print rounds*n + i